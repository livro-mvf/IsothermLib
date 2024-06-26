/** @defgroup SourceInfo Informacoes sobre as classes
 *  @ingroup Misceli¢nea
 *  Classe com informacoes sobre outras classes para fins de identificacao e localizacao de erros
 *  @{
 */


#ifndef __ISOTHERM_SOURCE_INFO_H__
#define __ISOTHERM_SOURCE_INFO_H__

//==============================================================================
// include c++
//==============================================================================

#include <string>

//==============================================================================
// include da biblioteca Isotherm
//==============================================================================
#include <Misc/Configure.h>

IST_NAMESPACE_OPEN 

class SourceInfo {
    
//==============================================================================
// Construtores / destrutora
//==============================================================================

public:
    
    SourceInfo() = default;
    SourceInfo(const SourceInfo&) = default;
    virtual ~SourceInfo() = default;
    SourceInfo(const std::string&, const long&, const std::string&);
    
//==============================================================================
// funcoes inline
//==============================================================================
    
    [[nodiscard]] inline std::string  FileLocation () const {return fileLocation;};
    [[nodiscard]] inline long         LinePosition () const {return lineLocation;};
    [[nodiscard]] inline std::string  FunctionName () const {return functionName;};
    
//==============================================================================
// Dados da classe
//==============================================================================
    
private :
    
    std::string         fileLocation;
    long                lineLocation    =   0;
    std::string         functionName;
    
};

#define IST_LOC SourceInfo( __FILE__, __LINE__, __FUNCT__)


IST_NAMESPACE_CLOSE
        
#endif  /* __ISOTHERM_SOURCE_INFO_H__ */
        
                
/** @} */    
        
        
   