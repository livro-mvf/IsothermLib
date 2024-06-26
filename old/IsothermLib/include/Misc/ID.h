/** @defgroup ID        Identificacao da Classe
 *  @ingroup Misceli¢nea
 *  Classe ID para identificacao das classes no caso de erro.
 *  @{
 */

//==============================================================================
// Name        : ID.h
// Author      : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe para identificacao de cada classe
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

#ifndef __ID_ISOTHERM_H__
#define __ID_ISOTHERM_H__

//==============================================================================
// include c++
//==============================================================================

#include <string>

//==============================================================================
// include da GeneticAlgorithm
//==============================================================================

#include <Misc/Configure.h>

IST_NAMESPACE_OPEN 

class ID {

//==============================================================================
// enum com o nome das classes da biblioteca
//==============================================================================
    
public:
    
  enum {
      
            Isotherm = 0
        ,   OneParameter
        ,   TwoParameters
        ,   ThreeParameters
        ,   FourParameters
        ,   FiveParameters
        ,   Henry = 100
        ,   DubininRadushkevich = 200
        ,   Elovich
        ,   Freundlich
        ,   HarkinJura
        ,   Halsey
        ,   Jovanovic
        ,   Langmuir
        ,   Temkin
        ,   Hill = 300
        ,   HillDeBoer
        ,   RedlichPeterson
        ,   Sips
        ,   Kiselev
        ,   FowlerGuggenheim
        ,   HollKrich
        ,   Jossens
        ,   Khan
        ,   Toth
        ,   ViethSladek
        ,   FritzSchlunder
        ,   LangmuirFreundlich
        ,   BrouersSotolongo
        ,   KobleCorrigan
        ,   BrunauerEmmettTeller
        ,   RadkePrausnitsI
        ,   RadkePrausnitsII
        ,   RadkePrausnitsIII
        ,   LangmuirJovanovic
        ,   MacMillanTeller
        ,   Unilan
        ,   ValenzuelaMyers
        ,   Baudu = 400
        ,   FritzSchlunderIV
        ,   MarczewskiJaroniec
        ,   WeberVanVliet
        ,   FritzSchlunderV = 500
        ,   FrenkelHalseyHill
        ,   Henderson       
  };    
    
//==============================================================================
// Construtores / destrutora
//==============================================================================

public:
    
    ID() = default;
    ID(const ID&) = default;
    virtual ~ID() = default;
    
//==============================================================================
// Sobrecarga de operadores
//==============================================================================

    ID& operator = (const ID&) = default;
    
//==============================================================================
// Funcoes virtuais
//==============================================================================
    
[[nodiscard]] inline  virtual std::string className() const {return "no class";}
[[nodiscard]] inline  virtual UInt classID() const {return 0;}

};

#define DefineIdentityBase( _name, _id) \
     virtual std::string className() const {return _name;} \
     virtual UInt classID() const {return _id;}

#define DefineIdentity( _name, _id) \
     virtual std::string className() const override  {return _name;} \
     virtual UInt classID() const override {return _id;}

#define DeclareIdentity() \
     const char * className() const; \
     int classID() const

//#define DefineIdentitySRC(_clss, _name, _id) \
//const char * _clss :: className() const {return _name;} \
//int _clss :: classID() const {return _id;}


IST_NAMESPACE_CLOSE

#endif /* __ID_ISOTHERM_H__ */
        
        
                
/** @} */    
        
        
   

