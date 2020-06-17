#ifndef UCLUSTPLUGIN_H
#define UCLUSTPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class UClustPlugin : public Plugin
{
public: 
 std::string toString() {return "UClust";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
};

#endif
