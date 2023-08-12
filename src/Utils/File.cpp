#include "File.hpp"

const char* kdr::file::getContents(const char* path) {
  std::ifstream file(path, std::ios::in | std::ios::binary);
  if (!file) {
    std::cerr << "Cannot read file: " << path << "!" << std::endl;
    return NULL;
  }

  file.seekg(0, std::ios::end);
  size_t fileSize = file.tellg();
  file.seekg(0, std::ios::beg);

  char* buffer = new char[fileSize + 1];
  file.read(buffer, fileSize);
  buffer[fileSize] = '\0';

  file.close();

  return buffer;
}
