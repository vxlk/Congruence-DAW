/*
  ==============================================================================

    congFileHandler.h
    Created: 20 Apr 2018 10:58:47am
    Author:  Tyler

  ==============================================================================
*/

#pragma once

#include <experimental/filesystem>
#include <fstream>
#include <vector>

namespace fs = std::experimental::filesystem;

class fileHandler {
 private:
    std::vector<std::string> contents;
 
 public:
    /* returns empty string if failure to open */
    inline const std::vector<std::string> getData(std::string folderName) {
		std::string congInitName = folderName + "Path.fpath";
        fs::path p = fs::path("..") / ".." / folderName;
	    std::string cpath = fs::canonical(p).string();
	    std::ofstream out;

		const std::vector<std::string> emptySet(1, "");
		if (!out) return emptySet;

		out.open(congInitName.c_str());
		/*read data*/
		
		//
		return contents;
    }
    
    inline const std::string getPath(std::string folderName) {
        fs::path p = fs::path("..") / ".." / folderName;
	    std::string cpath = fs::canonical(p).string();
        return cpath;
    }
 
    inline bool addNewPath(std::string type, std::string folderName) {
        std::string congInitName = type + "Path.fpath";
        ///todo: check caps in folder name maybe?
        fs::path p = fs::path("..") / ".." / folderName;
	    std::string cpath = fs::canonical(p).string();
	    std::ofstream out;
		if (!out) return false;
		out.open(congInitName.c_str());
		/* write data without overwriting other stuff */
		return true;
    }
    
	inline const std::string fixFileNameTooLong(std::string folderName) {
		///TODO:
		//decide on max length of file path for terminal
	}
};