#pragma once

namespace fw {

    double GetHighPercisionTime();
    void OutputMessage(const char* message, ...);
    char* LoadCompleteFile(const char* filename, long* length);
}