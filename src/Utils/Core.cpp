#include "Core.hpp"

const char* ENGINE_NAME    = "Kedar Engine";
const char* ENGINE_VERSION = "0.1";
const char* ENGINE_AUTHOR  = "sainttheforgotten";
const char* ENGINE_LICENSE = "GNU GPLv3";

void kdr::core::printEngineInfo()
{
  std::cout << ENGINE_NAME << " " << ENGINE_VERSION << std::endl;
  std::cout << "Created by " << ENGINE_AUTHOR << std::endl;
  std::cout << "Licensed under " << ENGINE_LICENSE << std::endl;
}
