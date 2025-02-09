#pragma once

#include "a3lzo.h"

#include "Types.h"

#include <istream>
#include <ostream>
#include <string>
#include <vector>
#include <chrono>
#include <array>
#include <type_traits>
#include <memory.h>

namespace grad_aff {

    // Read offset
    template<typename T>
    T readBytes(std::istream& i, std::streamoff offset);

    // Read
    template<typename T>
    T readBytes(std::istream& is);
    
    uint32_t readBytesAsArmaUShort(std::istream& is);

    template<typename T>
    T peekBytes(std::istream& is);

    XYZTriplet readXYZTriplet(std::istream &is);
    
    std::string readString(std::istream& is, int count);
    std::vector<uint8_t> readBytes(std::istream& is, std::streamsize length);

    std::string readZeroTerminatedString(std::istream& is);
    std::chrono::milliseconds readTimestamp(std::istream& is);

    uint32_t readCompressedInteger(std::istream& is);

    std::pair<std::vector<uint8_t>, size_t> readLZOCompressed(std::istream& is, size_t expectedSize);
    template<typename T>
    std::pair<std::vector<T>, size_t> readLZOCompressed(std::istream& is, size_t expectedSize);

    // Write
    template<typename T>
    void writeBytes(std::ostream& ofs, T t);
    
    void writeBytesAsArmaUShort(std::ostream& ofs, uint32_t t);

    void writeString(std::ostream& ofs, std::string string);
    void writeBytes(std::ostream& ofs, std::vector<uint8_t> bytes);

    void writeZeroTerminatedString(std::ostream& ofs, std::string string);
    void writeTimestamp(std::ostream& ofs, std::chrono::milliseconds milliseconds);
}