#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "AGEntPlugin.h"

void AGEntPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
   }
}

void AGEntPlugin::run() {
   
}

void AGEntPlugin::output(std::string file) {
	std::string command;
	// AGEnt.pl -r core_genome.fasta -q query_genome.fasta
   command = "AGEnt.pl ";
   command += " -r "+std::string(PluginManager::prefix())+"/"+parameters["core"];
   command += " -q "+std::string(PluginManager::prefix())+"/"+parameters["query"];
   command += " -o "+file;
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<AGEntPlugin> AGEntPluginProxy = PluginProxy<AGEntPlugin>("AGEnt", PluginManager::getInstance());
