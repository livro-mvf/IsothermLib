//=====================================================================================
// Name        : Henry.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Henry
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


//==============================================================================
// includes lib c++
//==============================================================================

#include <iostream>

//==============================================================================
// includes da lib Isotherm++
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/OneParameter/Henry.h>

//==============================================================================
// Variaveis estaticas
//==============================================================================

IST_NAMESPACE_OPEN

VecPairString       detailsHenry
    {
        PairString  ( "K1"
                    , "Coeficiente de distribuicao")
    };

template<>
VecPairString IsothermTemplate < Henry >::infoIsotherm = detailsHenry;


//==============================================================================
// Construtora com um parametro
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Henry :: Henry (const Real&)"
Henry :: Henry  (   const Real&     _k1)
                :   OneParameter (_k1)
{
    try {

        if (_k1 <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadK1LEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";
        exit(EXIT_FAILURE);

    }

    setup = true;

}

//==============================================================================
// Concentracao de equilibrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Henry ::  Qe (const Real&, const Real& = 0) const "
Real
Henry ::  Qe    (   const Real& _ce
                ,   const Real&)  const
{
    try {

        if (!setup) throw
            IsoException (IST_LOC, className(), BadCoefficient);

        if (_ce <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLEZero
                                );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
    }

    return   *(std::begin(coeffValue)) * _ce;

}

IST_NAMESPACE_CLOSE
