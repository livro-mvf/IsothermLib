//==============================================================================
// Name        : Config.h
// Authors     : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Arquivo onde são definidas algumas variáveis de
//               configuração do programa
//
// Copyright   : Copyright (C) 2024 Joao Flavio Vasconcellos (jflavio at iprj.uerj.br)
//
// Este programa é software livre: você pode redistribuí-lo e/ou modificá-lo
// sob os termos da Licença Pública Geral GNU, conforme publicada pela
// Free Software Foundation, tanto a versão 3 da Licença, ou (a seu critério)
// qualquer versão posterior.
//
// Este programa é distribuído na esperança de que possa ser útil,
// mas SEM NENHUMA GARANTIA, nem mesmo a garantia implícita de
// COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM PROPÓSITO ESPECÍFICO. Veja a
// Licença Pública Geral GNU para mais detalhes.
//
// Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este programa.
// Se não, veja <http://www.gnu.org/licenses/>.
//
//==============================================================================



/**
 * @defgroup NewtonRaphson Método de Newton-Raphson
 * @ingroup Miscelânea
 * Implementação do método de Newton-Raphson para o cálculo de raízes de funções.
 * @{
 */

#ifndef NEWTONRAPHSON_H_
#define NEWTONRAPHSON_H_

#include <Misc/Configure.h>     // Definição das vatiaveis
using namespace std::placeholders;

/**
 * @brief Tipo de função para representar uma função real de uma variável real.
 */
using NRFunction = std::function<Real(Real)>;

/**
 * @brief Implementa o método de Newton-Raphson para encontrar a raiz de uma função.
 * 
 * @param func A função cuja raiz queremos encontrar.
 * @param initial_guess A estimativa inicial para a raiz.
 * @return A raiz da função encontrada pelo método de Newton-Raphson.
 */
Real NewtonRaphson(NRFunction func, const Real& initial_guess);

#endif /* NEWTONRAPHSON_H_ */

/** @} */
