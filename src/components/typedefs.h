#ifndef TYPE_DEFS_H
#define TYPE_DEFS_H

#include <string>
#include <vector>
#include <map>

typedef int bit_t;
typedef std::vector<bit_t> wire_t;
typedef std::map<std::string, wire_t> component_io_t;

typedef std::vector<std::vector<std::pair<size_t, size_t>>> splitter_connection_t;

#endif // !TYPE_DEFS_H