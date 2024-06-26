//==============================================================================
// Name        : DubininRadushkevich.h
// Authors     : Iasmim Barboza Storck
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Dubinin-Radushkevich
//
// Copyright   : Copyright (C) <2021>  Joao Flavio Vasconcellos 
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


//==============================================================================
// include da lib c++ 
//==============================================================================

#include <cmath>                        // log
#include <iomanip>                      // std::setw, std::setprecision
#include <iostream>                     // std::cout
#include <string>                       // std::string

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Misc/Misc.h>                                      // PrintLine
#include <Isotherm/TwoParameters/DubininRadushkevich.h>     // ist::DubininRadushkevich

int main(int argc, char** argv) {

//==============================================================================
// Impressão do cabeçalho
//==============================================================================

std::string     MSG("exemplo da classe Dubinin-Radushkevich da biblioteca Isotherm++ ");

    PrintLine(std::cout);
    std::cout << "Inicio do " << MSG << "\n";
    PrintLine(std::cout);
//
////==============================================================================
//// Definição dos parâmetros
////==============================================================================
//
//const Real                      TEMP(400);                  // Temperatura em kelvin
//const Real                      CE(2e-3);                   // Concentração de equilíbrio
//                                                            // do adsorvato no adsorvente em mg / L
//const Real                      QMAX(150e-3);               // Quantidade de adosrvato em equilíbrio [mol/g]
//const Real                      K1(1e-8);                   // Constante de Dubinin-Radushkevich
//
//const    (QMAX, K1);
//const Real                      qe = isoterma.Qe(CE, TEMP);
//
////==============================================================================
//// imprimindo as informações sobre as constantes do modelo
////==============================================================================
//
//    std::cout << "\n";
//    PrintLine(std::cout);
//    std::cout << "Impressão de informações sobre as constantes\n";
//    PrintLine(std::cout);
//
//    std::cout   << isoterma
//                << std::endl;
//
//    std::cout   << "Numero de constantes de variável isoterma: "
//                << isoterma.NumberConst()
//                << std::endl;
//
//    std::cout << std::setfill(' ');
//    std::cout << "Impressao de informações da isoterma\n"
//              << std::setw(20)
//              << std::left
//              << "Parâmetro"
//              << std::setw(40)
//              << " Detalhe do parâmetro"
//              << std::right
//              << std::endl;
//
//    for (auto x : isoterma) {
//        std::cout   << std::setw(20)
//                    << std::left
//                    << x.first
//                    << std::setw(40)
//                    << x.second
//                    << std::right
//                    << "\n";
//    }
//
//
//    std::cout << "\n\nPara a temperatura: " << TEMP
//              << " e concentração de equilíbrio: " << CE
//              << " tem-se que qe = " << qe
//              << std::endl;
//
////==============================================================================
//// imprimindo a curva da isoterma
////==============================================================================
//
//const Real          CMIN(1E-3);                     // valor minimo da concentração
//const Real          CMAX(1.5);                      // valor máximo da concentração
//const UInt          NPTO(1001);                      // numero de pontos gerados
//
//auto EixoX = [](const Real& _qe, const Real&_ce)    // Função de linearização da isoterma no eixo X
//{
//
//Real auxi = log(1 + 1.0 / _ce);
//
//    return  auxi * auxi;
//
//};
//
//auto EixoY = [isoterma, TEMP](const Real& _qe, const Real&_ce)       // Função de linearização da isoterma no eixo y
//{
//
//    auto auxi =    1.0 / (isoterma.Rgas() * TEMP);
//    return - log( _qe ) * auxi * auxi;
//
//};
//
//const std::string FILENAME("Figuras/CasoL400.dat");
//
//    std::cout << "\n";
//    PrintLine(std::cout);
//    std::cout << "Impressão dos gráfico no arquivo: " << FILENAME << "\n";
//    PrintLine(std::cout);
//
//    isoterma.PlotGraph  (   FILENAME
//                        ,   EixoX
//                        ,   EixoY
//                        ,   NPTO
//                        ,   CMIN
//                        ,   CMAX
//                        ,   TEMP);
//
////==============================================================================
//// Fim do programa exemplo
////==============================================================================
//
//    std::cout << "\n\n";
//    PrintLine(std::cout);
//    std::cout << "Fim do " << MSG << "\n";
//    PrintLine(std::cout);
//
    return 0;
}

