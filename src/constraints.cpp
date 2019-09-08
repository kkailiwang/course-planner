
#include "constraints.h"


static Map<string, req> buildGeneralReqMap() {

    Map<string, req> generalReqs;
    generalReqs["WAY-A-II"] =   {MIN_COUNT, 2, WAYS};
    generalReqs["WAY-AQR"] =    {MIN_COUNT, 1, WAYS};
    generalReqs["WAY-SMA"] =    {MIN_COUNT, 2, WAYS};

    return generalReqs;
}

static Map<string, int> buildYearSpecificReqMap() {

    Map<string, int> yearSpecificReqs;
    yearSpecificReqs["Writing 1"] =     1;
    //later add Writing 2 and THINK.

    return yearSpecificReqs;
}

//static const Map<string, req> GENERAL_REQ = buildGeneralReqMap();
//static const Map<string, int> YEAR_SPECIFIC_REQ = buildYearSpecificReqMap();

void buildConcentrationReqMap(Map<string, req> &concReqs) {


}
