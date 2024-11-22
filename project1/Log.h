#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>
#define INF 0
#define DBG 1
#define ERR 2
#define LOG_LEVEL DBG

#define LOG(level, format, ...) do {\
    if (level < LOG_LEVEL) break;\
    auto now = std::chrono::system_clock::now();\
    auto now_c = std::chrono::system_clock::to_time_t(now);\
    std::tm now_tm;\
    localtime_s(&now_tm, &now_c);\
    char tmp[32] = {0};\
    strftime(tmp, 31, "%H:%M:%S", &now_tm);\
    std::stringstream ss;\
    ss << "[" << std::this_thread::get_id() << " " << tmp << " " << __FILE__ << ":" << __LINE__ << "] ";\
    ss << format;\
    std::cout << ss.str() << std::endl;\
} while(0)

#define INF_LOG(format, ...) LOG(INF, format, ##__VA_ARGS__)
#define DBG_LOG(format, ...) LOG(DBG, format, ##__VA_ARGS__)
#define ERR_LOG(format, ...) LOG(ERR, format, ##__VA_ARGS__)