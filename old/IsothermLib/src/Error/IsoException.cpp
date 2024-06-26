//==============================================================================
// Name        : IsoException.cpp
// Author      : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Implementação da classe IsoException
//
// Copyright   : Copyright (C) <2022>  Joao Flavio Vasconcellos 
//                                      (jflavio at iprj.uerj.br)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//==============================================================================

#include <iostream>
#include <Error/IsoException.h>
#include <Misc/Misc.h>

IST_NAMESPACE_OPEN

namespace {

/*! \var std::string IsoExceptionStr[]
 *  \brief Array de strings que descrevem as exceções.
 */
const std::string IsoExceptionStr[] = {
    "Coeficientes da isoterma indefinidos.",                   // BadCoefficient
    "Ce menor ou igual a zero.",                               // BadCeLEZero
    "Ce menor do que zero.",                                   // BadCeLTZero    
    "Ce maior ou igual a 1.",                                  // BadCeGEOne    
    "Ce maior ou igual a K2.",                                 // BadCeGEK2  
    "K1 menor ou igual a zero.",                               // BadK1LEZero
    "K1 menor do que zero.",                                   // BadK1LTZero
    "K2 menor ou igual a zero.",                               // BadK2LEZero
    "K2 menor do que zero.",                                   // BadK2LTZero   
    "K3 menor ou igual a zero.",                               // BadK3LEZero
    "K3 menor do que zero.",                                   // BadK3LTZero  
    "K4 menor ou igual a zero.",                               // BadK4LEZero
    "K4 menor do que zero.",                                   // BadK4LTZero  
    "K1 menor do que 1.",                                      // BadK1LTOne
    "K2 menor ou igual a 1.",                                  // BadK2LEOne
    "K3 maior do que 1.",                                      // BadK3GTOne     
    "K3 maior ou igual a 1.",                                  // BadK3GEOne     
    "Qmax menor ou igual a zero.",                             // BadQmaxLEZero 
    "Temperatura menor ou igual a zero.",                      // BadTempLEZero
    "Constante universal dos gases menor ou igual a zero.",    // BadRGasLEZero
    "Resultado inconsistente para o modelo.",                  // BadResult
    "Overflow de operacao matematica.",                        // BadOverFlow
    "O valor de log(C) maior que K_2.",                        // BadLogCeGTK2
    "Problema de convergencia do metodo iterativo.",           // ConvergenceProblem
    "O valor de theta maior ou igual a 1.",                    // BadThetaGEOne
    "O valor de theta menor ou igual a 0.",                    // BadThetaLEZero
    "O valor de K_1 C menor ou igual a 1."                     // BadKCeK1LEOne
};

}  // namespace

IsoException::IsoException(const SourceInfo& source_info,
                           const std::string& classe,
                           const IsoExceptionIndex& index,
                           const std::string& msg1,
                           const std::string& msg2)
    : source_info_(source_info), classe_(classe), index_(index), msg1_(msg1), msg2_(msg2) {
}

std::ostream& operator<<(std::ostream& os, const IsoException& ex) {
    os << "\n\n";
    PrintLine(os);   
    os  << "Erro:    " 
        << IsoExceptionStr[static_cast<int>(ex.index_)] 
        << "\nClasse:  " 
        << ex.classe_ 
        << "\nFuncao:  " 
        << ex.source_info_.FunctionName() 
        << "\nArquivo: " 
        << ex.source_info_.FileLocation() 
        << "\nLinha:   " 
        << ex.source_info_.LinePosition() 
        << "\n";
    
    if (!ex.msg1_.empty()) {
        os  << "Msg:     " 
            << ex.msg1_ 
            << "\n";        
    
        if (!ex.msg2_.empty()) {
            os  << "         " 
                << ex.msg2_ 
                << "\n";        
        }
    }
    
    std::cout << "Execucao cancelada\n";
    PrintLine(os);           
    
    return os;
}

IST_NAMESPACE_CLOSE
