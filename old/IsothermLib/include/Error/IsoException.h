//==============================================================================
// Name        : IsoException.h
// Author      : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe para tratar as exceptions do programa
//
// Copyright   : Copyright (C) <2024>  Joao Flavio Vasconcellos 
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

/*! \file IsoException.h
 *  \brief Classe para tratar as exceptions do programa
 */

#ifndef ISOEXCEPTION_H_
#define ISOEXCEPTION_H_

#include <exception>
#include <string>
#include <Misc/Configure.h>
#include <Misc/SourceInfo.h>

IST_NAMESPACE_OPEN

/*!
 *  \enum IsoExceptionIndex
 *  \brief Enumeração dos diferentes tipos de exceções.
 */
enum IsoExceptionIndex {
    BadCoefficient = 0,  ///< Coeficiente inválido
    BadCeLEZero,         ///< Ce menor ou igual a zero
    BadCeLTZero,         ///< Ce menor que zero
    BadCeGEOne,          ///< Ce maior ou igual a um
    BadCeGEK2,           ///< Ce maior ou igual a K2
    BadK1LEZero,         ///< K1 menor ou igual a zero
    BadK1LTZero,         ///< K1 menor que zero
    BadK2LEZero,         ///< K2 menor ou igual a zero
    BadK2LTZero,         ///< K2 menor que zero
    BadK3LEZero,         ///< K3 menor ou igual a zero
    BadK3LTZero,         ///< K3 menor que zero
    BadK4LEZero,         ///< K4 menor ou igual a zero
    BadK4LTZero,         ///< K4 menor que zero
    BadK1LTOne,          ///< K1 menor que um
    BadK2LEOne,          ///< K2 menor ou igual a um
    BadK3GTOne,          ///< K3 maior que um
    BadK3GEOne,          ///< K3 maior ou igual a um
    BadQmaxLEZero,       ///< Qmax menor ou igual a zero
    BadTempLEZero,       ///< Temperatura menor ou igual a zero
    BadRGasLEZero,       ///< R Gas menor ou igual a zero
    BadResult,           ///< Resultado inválido
    BadOverFlow,         ///< Overflow
    BadLogCeGTK2,        ///< Log(Ce) maior ou igual a K2
    ConvergenceProblem,  ///< Problema de convergência
    BadThetaGEOne,       ///< Theta maior ou igual a um
    BadThetaLEZero,      ///< Theta menor ou igual a zero
    BadKCeK1LEOne        ///< KCe/K1 menor ou igual a um
};

/*!
 *  \class IsoException
 *  \brief Classe para tratar as exceções do programa.
 */
class IsoException : public std::exception {
 public:
  /*!
   *  \brief Construtor da classe IsoException.
   *  \param source_info Informações sobre a origem da exceção.
   *  \param classe Nome da classe onde ocorreu a exceção.
   *  \param index Índice da exceção.
   *  \param msg1 Mensagem adicional 1.
   *  \param msg2 Mensagem adicional 2.
   */
  IsoException(const SourceInfo& source_info,
               const std::string& classe,
               const IsoExceptionIndex& index,
               const std::string& msg1 = "",
               const std::string& msg2 = "");

  /*!
   *  \brief Construtor da classe IsoException.
   *  \param msg Mensagem da exceção.
   *  \param funct Função onde ocorreu a exceção.
   *  \param arquivo Arquivo onde ocorreu a exceção.
   *  \param linha Linha do arquivo onde ocorreu a exceção.
   */
  IsoException(const std::string& msg,
               const std::string& funct,
               const std::string& arquivo,
               const unsigned int& linha) {}

  IsoException(const IsoException&) = default;
  ~IsoException() override = default;

  /*!
   *  \brief Retorna a mensagem de erro.
   *  \return Mensagem de erro.
   */
  const char* what() const noexcept override {
    return msg_.c_str();
  }

  friend std::ostream& operator<<(std::ostream& os, const IsoException& ex);

 private:
  SourceInfo source_info_;
  std::string classe_;
  IsoExceptionIndex index_;
  std::string msg1_;
  std::string msg2_;
  std::string msg_;
};

IST_NAMESPACE_CLOSE

#endif  // ISOEXCEPTION_H_
