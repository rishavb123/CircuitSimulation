#ifndef TYPE_DEFS_H
#define TYPE_DEFS_H

#include <string>
#include <vector>
#include <unordered_map>

typedef bool bit_t;
typedef std::vector<bit_t> wire_t;
typedef std::unordered_map<std::string, wire_t> component_io_t;

#endif // !TYPE_DEFS_H