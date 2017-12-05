#include "GridMapCereal.hpp"

#include "cereal/archives/binary.hpp"

#include <fstream>

void saveGridMap(const grid_map::GridMap& map, const std::string& filename) {
    std::ofstream streamOut(filename, std::ios::binary);
    cereal::BinaryOutputArchive archiveOut(streamOut);

    archiveOut(map);
}

void loadGridMap(grid_map::GridMap& map, const std::string& filename) {
    std::ifstream streamIn(filename, std::ios::binary);
    cereal::BinaryInputArchive archiveIn(streamIn);

    archiveIn(map);
}

