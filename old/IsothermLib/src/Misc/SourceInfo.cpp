#include <Misc/SourceInfo.h>

IST_NAMESPACE_OPEN 

SourceInfo :: SourceInfo    (       const std::string&      _file 
                            ,       const long&             _line
                            ,       const std::string&      _function
                            ) 
                            :       fileLocation(_file) 
                            ,       lineLocation (_line)
                            ,       functionName(_function) 
{
}
        
IST_NAMESPACE_CLOSE