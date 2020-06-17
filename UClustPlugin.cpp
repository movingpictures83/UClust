#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "UClustPlugin.h"

void UClustPlugin::input(std::string file) {
 inputfile = file;
}

void UClustPlugin::run() {
   
}

void UClustPlugin::output(std::string file) {
//beta_diversity.py -i filtered_otu_table.biom -m euclidean,weighted_unifrac,unweighted_unifrac -t rep_set.tre -o beta_div
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; pick_otus.py ";
 command += "-i "+inputfile+" ";
 command += "-o "+file+"; cp "+file+"/*.uc "+file+"/..; cp "+file+"/*.txt "+file+"/..; export PYTHONPATH=OLDPATH";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<UClustPlugin> UClustPluginProxy = PluginProxy<UClustPlugin>("UClust", PluginManager::getInstance());
