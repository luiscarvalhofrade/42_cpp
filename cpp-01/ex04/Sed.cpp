/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:14:10 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/07 13:43:36 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

bool processFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open input file '" << filename << "'" << std::endl;
        return false;
    }
    
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create output file '" << outputFilename << "'" << std::endl;
        inputFile.close();
        return false;
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string processedLine = replaceString(line, s1, s2);
        outputFile << processedLine << std::endl;
    }
    
    inputFile.close();
    outputFile.close();
    return true;
}

std::string replaceString(const std::string& text, const std::string& s1, const std::string& s2) {
    if (s1.empty()) return text;
    
    std::string result = text;
    std::string::size_type pos = 0;
    
    while ((pos = result.find(s1, pos)) != std::string::npos) {
        result = result.substr(0, pos) + s2 + result.substr(pos + s1.length());
        pos += s2.length();
    }
    
    return result;
}