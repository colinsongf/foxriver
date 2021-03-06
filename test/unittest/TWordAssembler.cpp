#include "gtest/gtest.h"
#include "src/WordAssembler.hpp"

const char * const DICT_PATH = "../dict/dict.utf8";
const char * const HMM_PATH = "../dict/hmm_model.utf8";
const char * const IDF_PATH = "../dict/idf.utf8";
const char * const STOPWORD_PATH = "../dict/stop_words.utf8";
const char * const TIME_DICT_PATH = "../dict/time.utf8";
const char * const CITY_PATH = "../dict/city.xml";
const char * const LOCATION_PATH = "../dict/location.xml";

const char * const SENTENCE = "明天我要去上海，帮我定个浦东新区的酒店";

using namespace FoxRiver;

TEST(TWordAssembler, test1)
{
    WordAssembler wordAssembler(DICT_PATH, HMM_PATH, IDF_PATH, STOPWORD_PATH, TIME_DICT_PATH, CITY_PATH, LOCATION_PATH);
    string res;
    wordAssembler.run(SENTENCE, res);
    KeyInfo keyInfo;
    wordAssembler.convertTime("明天", keyInfo.time);
    keyInfo.cityInfo.name = "上海";
    keyInfo.cityInfo.id = "2";
    keyInfo.cityInfo.code = "SHA";
    keyInfo.locationInfo.id = "119";
    keyInfo.locationInfo.name = "浦东新区";
    keyInfo.locationInfo.cityId = "2";
    string s1, s2;
    s1 << keyInfo;
    s2 << res;
    ASSERT_EQ(s1, s2);
}

