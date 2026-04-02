#pragma once
#include <string>
#include <vector>

/// Load a comma-separated values file into a 2-D vector of doubles.
/// Each row in the file becomes one inner vector; the file must contain
/// only numeric values (no header row).
/// Throws std::runtime_error if the file cannot be opened.
std::vector<std::vector<double>> loadCSV(const std::string& path);
