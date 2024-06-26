#ifndef DUBININ_RADUSHKEVICH_H_
#define DUBININ_RADUSHKEVICH_H_

//==============================================================================
// Includes
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

IST_NAMESPACE_OPEN

//==============================================================================
// Class DubininRadushkevich
//==============================================================================

/**
 * @defgroup DubininRadushkevich Dubinin-Radushkevich
 * @ingroup Two_Parameters
 * @brief Classe com as equa��es da isoterma de Dubinin-Radushkevich.
 */

/**
 * @brief Classe que implementa as equa��es da isoterma de Dubinin-Radushkevich.
 *
 * Esta classe define as equa��es utilizadas para calcular a isoterma de Dubinin-Radushkevich,
 * que envolve os par�metros q_max e K_1.
 *
 * Refer�ncia: https://doi.org/10.1021/cr60204a006
 *
 * @authors
 * - Iasmim Barboza Storck
 * - Lara Botelho Brum
 * - Luan Rodrigues Soares de Souza
 * - Joao Flavio Vieira de Vasconcellos
 * @version 1.0
 * @date 2022
 * @bug Nenhum bug conhecido.
 * @see IsothermTemplate
 */
class DubininRadushkevich : public virtual TwoParameters, public IsothermTemplate<DubininRadushkevich> {
 public:
    /**
     * @brief Construtor padr�o.
     *
     * @note Utiliza os valores padr�o para q_max, K_1 e RGASCONST.
     */
    DubininRadushkevich();

    /**
     * @brief Construtor de c�pia.
     *
     * @param _orig Objeto DubininRadushkevich original a ser copiado.
     */
    DubininRadushkevich(const DubininRadushkevich& _orig);

    /**
     * @brief Construtor com par�metros personalizados.
     *
     * @param _qmax Constante de equil�brio de Dubinin-Radushkevich.
     * @param _k1 Coeficiente associado � energia de adsor��o.
     * @param _rgas Valor da constante universal dos gases diferente do padr�o.
     * @exception std::invalid_argument se _qmax <= 0 ou _k1 <= 0 ou _rgas <= 0.
     */
    DubininRadushkevich(const Real& _qmax, const Real& _k1, const Real& _rgas = Isotherm::RGASCONST);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~DubininRadushkevich();

    /**
     * @brief Sobrecarga do operador de atribui��o.
     *
     * @param _orig Objeto DubininRadushkevich original a ser atribu�do.
     * @return Refer�ncia para o objeto atual.
     */
    DubininRadushkevich& operator=(const DubininRadushkevich& _orig);

    /**
     * @brief Retorna o valor de q_max.
     *
     * @return Valor de q_max.
     */
    [[nodiscard]] inline Real Qmax() const;

    /**
     * @brief Retorna o valor de K_1.
     *
     * @return Valor de K_1.
     */
    [[nodiscard]] inline Real K1() const;

    /**
     * @brief Retorna o valor da constante universal dos gases (RGAS).
     *
     * @return Valor de RGAS.
     */
    [[nodiscard]] inline Real Rgas() const;

    /**
     * @brief Define um novo valor para q_max.
     *
     * @param _qmax Novo valor para q_max.
     * @exception std::invalid_argument se _qmax <= 0.
     */
    inline void Qmax(const Real& _qmax);

    /**
     * @brief Define um novo valor para K_1.
     *
     * @param _k1 Novo valor para K_1.
     * @exception std::invalid_argument se _k1 <= 0.
     */
    inline void K1(const Real& _k1);

    /**
     * @brief Define um novo valor para RGAS.
     *
     * @param _rgas Novo valor para RGAS.
     * @note Esta fun��o est� marcada como maybe_unused pois a constante dos gases pode n�o ser modificada frequentemente.
     */
    [[maybe_unused]] inline void Rgas(const Real& _rgas);

    /**
     * @brief Calcula a quantidade de sor��o no equil�brio para uma dada concentra��o e temperatura.
     *
     * @param _c Concentra��o do soluto.
     * @param _temp Temperatura em Kelvin.
     * @return Quantidade de sor��o no equil�brio.
     * @exception std::invalid_argument se _c <= 0 ou _temp <= 0.
     */
    [[nodiscard]] Real Qe(const Real& _c, const Real& _temp) const;

    /**
     * @brief Calcula a quantidade de sor��o no equil�brio para uma dada concentra��o.
     *
     * @param _c Concentra��o do soluto.
     * @return Quantidade de sor��o no equil�brio.
     * @exception std::invalid_argument se _c <= 0.
     */
    [[nodiscard]] inline Real Qe(const Real& _c) const override;

    /**
     * @brief Cria uma c�pia do objeto utilizando polimorfismo.
     *
     * @return Ponteiro �nico para a c�pia da classe DubininRadushkevich.
     */
    [[maybe_unused]] [[nodiscard]] virtual std::unique_ptr<Isotherm> CloneImplementation() const override;

 private:
    Real RGAS = Isotherm::RGASCONST; ///< Valor padr�o da constante universal dos gases.
};

IST_NAMESPACE_CLOSE

#endif // DUBININ_RADUSHKEVICH_H_
