#ifndef __ISOTHERM_ERROR_H__
#define __ISOTHERM_ERROR_H__

//==============================================================================
// include c++
//==============================================================================

#include <string>

//==============================================================================
// include da Isotherm++
//==============================================================================

#include <Misc/Configure.h>
#include <Misc/SourceInfo.h>


IST_NAMESPACE_OPEN


enum IsoErrorIndex {
//    
//  Erros Gerais
//    
        BadCoeffDefinition = 0

};

void ISOTHERM_Err(  const SourceInfo&,
                    const std::string&, 
                    const IsoErrorIndex&, 
                    const std::string& = "",
                    const std::string& = "");

IST_NAMESPACE_CLOSE

#endif /* __ISOTHERM_ERROR_H__ */

