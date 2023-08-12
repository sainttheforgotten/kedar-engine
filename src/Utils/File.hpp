#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <iostream>

namespace kdr {
  namespace file {
    /**
     * Reads the contents of a file and returns them as a character array.
     *
     * @param path The path to the file to be read.
     * @return A character array containing the file contents, or NULL if the file cannot be read.
     */
    const char* getContents(const char* path);
  }
}

#endif // FILE_HPP
