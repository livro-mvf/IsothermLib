//==============================================================================
// Name        : Config.h
// Authors     : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Arquivo onde s�o definidas algumas vari�veis de
//               configura��o do programa
//
// Copyright   : Copyright (C) 2024 Joao Flavio Vasconcellos (jflavio at iprj.uerj.br)
//
// Este programa � software livre: voc� pode redistribu�-lo e/ou modific�-lo
// sob os termos da Licen�a P�blica Geral GNU, conforme publicada pela
// Free Software Foundation, tanto a vers�o 3 da Licen�a, ou (a seu crit�rio)
// qualquer vers�o posterior.
//
// Este programa � distribu�do na esperan�a de que possa ser �til,
// mas SEM NENHUMA GARANTIA, nem mesmo a garantia impl�cita de
// COMERCIALIZA��O ou ADEQUA��O A UM PROP�SITO ESPEC�FICO. Veja a
// Licen�a P�blica Geral GNU para mais detalhes.
//
// Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU junto com este programa.
// Se n�o, veja <http://www.gnu.org/licenses/>.
//
//==============================================================================



/**
 * @defgroup NewtonRaphson M�todo de Newton-Raphson
 * @ingroup Miscel�nea
 * Implementa��o do m�todo de Newton-Raphson para o c�lculo de ra�zes de fun��es.
 * @{
 */

#ifndef NEWTONRAPHSON_H_
#define NEWTONRAPHSON_H_

#include <Misc/Configure.h>     // Defini��o das vatiaveis
using namespace std::placeholders;

/**
 * @brief Tipo de fun��o para representar uma fun��o real de uma vari�vel real.
 */
using NRFunction = std::function<Real(Real)>;

/**
 * @brief Implementa o m�todo de Newton-Raphson para encontrar a raiz de uma fun��o.
 * 
 * @param func A fun��o cuja raiz queremos encontrar.
 * @param initial_guess A estimativa inicial para a raiz.
 * @return A raiz da fun��o encontrada pelo m�todo de Newton-Raphson.
 */
Real NewtonRaphson(NRFunction func, const Real& initial_guess);

#endif /* NEWTONRAPHSON_H_ */

/** @} */
