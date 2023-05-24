#pragma once

#include <ctime>
#include <chrono>
#include <string>
#include <vector>

#include <iomanip>
#include <sstream>
#include <iostream>
//#include <openssl/sha.h>

using namespace std;

/**
 * Convert a string to a time_t object
 * @param input input string
 */
static time_t strToTime(const string &input) {
    tm time{};
    stringstream ss(input);
    ss >> get_time(&time, "%d-%m-%Y");

    return mktime(&time);
}

/**
 * Convert a time_t object to a string
 * @param input
 * @return
 */
static string timeToStr(const time_t &input) {
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", std::localtime(&input));
    return {buffer};
}

/**
 * Convert a string object to lowercase
 * @param str
 * @return
 */
static string toLower(string str) {
    for (char &c: str)
        c = char(tolower(c));

    return str;
}


/**
 * Formats a float to a string with a given precision
 * @param value
 * @param precision
 * @return
 */
static string formatFloat(float value, int precision) {
    std::ostringstream stream;
    stream << fixed << setprecision(precision) << value;
    return stream.str();
}


/**
 * Checks if a string has the correct Date format
 * @param dateStr
 * @return
 */
static bool isDateFormatValid(const string &dateStr) {
    tm date{};
    istringstream ss(dateStr);
    ss >> get_time(&date, "%d-%m-%Y");
    return !ss.fail() && ss.eof();
}

/**
 * @brief Computes the SHA256 hash of a string
 * @param str
 * @return
 */
static string sha256(const string &str) {
//    unsigned char hash[SHA256_DIGEST_LENGTH];
//    SHA256_CTX sha256;
//    SHA256_Init(&sha256);
//    SHA256_Update(&sha256, str.c_str(), str.length());
//    SHA256_Final(hash, &sha256);
//
//    string hashedPassword;
//    char hex[3];
//    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
//        sprintf(hex, "%02x", hash[i]);
//        hashedPassword += hex;
//    }
//
//    return hashedPassword;

    return str;
}