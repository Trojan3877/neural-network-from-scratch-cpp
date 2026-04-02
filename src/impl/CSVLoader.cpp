#include "CSVLoader.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<std::vector<double>> loadCSV(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("CSVLoader: cannot open file: " + path);

    std::vector<std::vector<double>> data;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string cell;
        std::vector<double> row;
        while (std::getline(ss, cell, ','))
            row.push_back(std::stod(cell));
        if (!row.empty())
            data.push_back(std::move(row));
    }
    return data;
}