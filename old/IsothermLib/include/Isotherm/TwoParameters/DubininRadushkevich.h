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
 * @brief Classe com as equações da isoterma de Dubinin-Radushkevich.
 */

/**
 * @brief Classe que implementa as equações da isoterma de Dubinin-Radushkevich.
 *
 * Esta classe define as equações utilizadas para calcular a isoterma de Dubinin-Radushkevich,
 * que envolve os parâmetros q_max e K_1.
 *
 * Referência: https://doi.org/10.1021/cr60204a006
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
     * @brief Construtor padrão.
     *
     * @note Utiliza os valores padrão para q_max, K_1 e RGASCONST.
     */
    DubininRadushkevich();

    /**
     * @brief Construtor de cópia.
     *
     * @param _orig Objeto DubininRadushkevich original a ser copiado.
     */
    DubininRadushkevich(const DubininRadushkevich& _orig);

    /**
     * @brief Construtor com parâmetros personalizados.
     *
     * @param _qmax Constante de equilíbrio de Dubinin-Radushkevich.
     * @param _k1 Coeficiente associado à energia de adsorção.
     * @param _rgas Valor da constante universal dos gases diferente do padrão.
     * @exception std::invalid_argument se _qmax <= 0 ou _k1 <= 0 ou _rgas <= 0.
     */
    DubininRadushkevich(const Real& _qmax, const Real& _k1, const Real& _rgas = Isotherm::RGASCONST);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~DubininRadushkevich();

    /**
     * @brief Sobrecarga do operador de atribuição.
     *
     * @param _orig Objeto DubininRadushkevich original a ser atribuído.
     * @return Referência para o objeto atual.
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
     * @note Esta função está marcada como maybe_unused pois a constante dos gases pode não ser modificada frequentemente.
     */
    [[maybe_unused]] inline void Rgas(const Real& _rgas);

    /**
     * @brief Calcula a quantidade de sorção no equilíbrio para uma dada concentração e temperatura.
     *
     * @param _c Concentração do soluto.
     * @param _temp Temperatura em Kelvin.
     * @return Quantidade de sorção no equilíbrio.
     * @exception std::invalid_argument se _c <= 0 ou _temp <= 0.
     */
    [[nodiscard]] Real Qe(const Real& _c, const Real& _temp) const;

    /**
     * @brief Calcula a quantidade de sorção no equilíbrio para uma dada concentração.
     *
     * @param _c Concentração do soluto.
     * @return Quantidade de sorção no equilíbrio.
     * @exception std::invalid_argument se _c <= 0.
     */
    [[nodiscard]] inline Real Qe(const Real& _c) const override;

    /**
     * @brief Cria uma cópia do objeto utilizando polimorfismo.
     *
     * @return Ponteiro único para a cópia da classe DubininRadushkevich.
     */
    [[maybe_unused]] [[nodiscard]] virtual std::unique_ptr<Isotherm> CloneImplementation() const override;

 private:
    Real RGAS = Isotherm::RGASCONST; ///< Valor padrão da constante universal dos gases.
};

IST_NAMESPACE_CLOSE

#endif // DUBININ_RADUSHKEVICH_H_
