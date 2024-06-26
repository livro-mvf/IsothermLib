//==============================================================================
// Name        : TesteTemkin.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe Temkin
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
// include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/Temkin.h>     // ist::Temkin

//==============================================================================
// include da googletest
//==============================================================================
#include <gtest/gtest.h>

typedef     ist::Temkin TestIsotherm;

class TestSuit : public ::testing::Test {  
    
protected: 
    

const Real              K1          = 0.876338;    
const Real              K2          = 0.730948;    
const Real              CE          = 4.188692034; 
const Real              TEMP        = 88.0658;
const Real              RGASNovo    = 4.157231309;      
const Real              K2Novo      = 34.548;    
const Real              K1Novo      = 98.1e-03;    


public:
        
    TestIsotherm     isotherm_1;    
    TestIsotherm     isotherm_2 = TestIsotherm(K1, K2, RGASNovo);    
    TestIsotherm     isotherm_3 = TestIsotherm(isotherm_2);    

};  

TEST_F(TestSuit, ConstrutorDefault) {
 
    EXPECT_EQ(isotherm_1.K2(), 0);
    EXPECT_EQ(isotherm_1.K1(), 0);
    EXPECT_EQ(isotherm_1.Rgas(), 8.31446261815324);
    EXPECT_EQ(isotherm_1.NumberConst(), 2);
    EXPECT_DEATH(auto value = isotherm_1.Qe(CE, TEMP);, "");
  
}

TEST_F(TestSuit, ConstrutorPadrao) {
    
  EXPECT_EQ(isotherm_2.Rgas(), RGASNovo);
  EXPECT_EQ(isotherm_2.K2(), K2);
  EXPECT_EQ(isotherm_2.K1(), K1);  
  EXPECT_EQ(isotherm_2.NumberConst(), 2);

  isotherm_2.K2(K2Novo);
  isotherm_2.K1(K1Novo);

  EXPECT_EQ(isotherm_2.K2(), K2Novo);
  EXPECT_EQ(isotherm_2.K1(), K1Novo);
}

TEST_F(TestSuit, ConstrutoraDeCopia) {

  EXPECT_EQ(isotherm_3.K2(), K2);
  EXPECT_EQ(isotherm_3.K1(), K1);
  EXPECT_EQ(isotherm_3.Rgas(), RGASNovo);
  EXPECT_EQ(isotherm_3.NumberConst(), 2);

  isotherm_3.Rgas(2 * RGASNovo);
  isotherm_3.K2(K2Novo);
  isotherm_3.K1(K1Novo);

  EXPECT_EQ(isotherm_3.K2(), K2Novo);
  EXPECT_EQ(isotherm_3.K1(), K1Novo);
  EXPECT_EQ(isotherm_3.Rgas(), 2 * RGASNovo);
  
}


TEST_F(TestSuit, CalculoQe) {


const Real                      QEANALIT1(1302.647690);
const Real                      QEANALIT2(651.3238448);

const TestIsotherm              iso1 (K1, K2);
const TestIsotherm              iso2 (K1, K2, RGASNovo);
std::unique_ptr<ist::Isotherm>  iso1c = iso1.Clone();
std::unique_ptr<ist::Isotherm>  iso2c = iso2.Clone();

    EXPECT_FLOAT_EQ ( iso1.Qe(CE, TEMP), QEANALIT1);
    EXPECT_FLOAT_EQ ( iso2.Qe(CE, TEMP), QEANALIT2);
    EXPECT_FLOAT_EQ ( iso1c->Qe(CE, TEMP), QEANALIT1);
    EXPECT_FLOAT_EQ ( iso2c->Qe(CE, TEMP), QEANALIT2);
    EXPECT_DEATH(auto value = iso1c->Qe(- CE, TEMP);, "");
    EXPECT_DEATH(auto value = iso1c->Qe( 0.0, TEMP);, "");
    EXPECT_DEATH(auto value = iso1c->Qe( CE, -TEMP);, "");
    EXPECT_DEATH(auto value = iso1c->Qe( CE, 0);, "");
}


TEST_F(TestSuit, DeathTest) {
    
    EXPECT_DEATH(TestIsotherm( 0.0 ,  K2);, "");
    EXPECT_DEATH(TestIsotherm(- K1 ,  K2);, ""); 

    EXPECT_DEATH(TestIsotherm(  K1 ,  - K2);, "");
    EXPECT_DEATH(TestIsotherm(K1 ,  0.0);, "");

    EXPECT_DEATH(TestIsotherm(  K1 ,   K2, - RGASNovo);, "");
    EXPECT_DEATH(TestIsotherm(  K1 ,   K2, 0.0);, "");
    
    EXPECT_DEATH(auto value = isotherm_2.Qe(- CE,   TEMP);, "");
    EXPECT_DEATH(auto value = isotherm_2.Qe( 0.0,   TEMP);, "");

    EXPECT_DEATH(auto value = isotherm_2.Qe(  CE, - TEMP);, "");
    EXPECT_DEATH(auto value = isotherm_2.Qe(  CE,    0.0);, "");

    
    EXPECT_DEATH(auto value = isotherm_2.Qe( 1.0 / K1,   TEMP);, "");
    
    EXPECT_DEATH(isotherm_2.K1( - K1);, "");
    EXPECT_DEATH(isotherm_2.K1(  0.0);, "");
    
    EXPECT_DEATH(isotherm_2.K2(- K2);, "");
    EXPECT_DEATH(isotherm_2.K2(   0.0);, "");
    
    EXPECT_DEATH(isotherm_2.Rgas(- RGASNovo);, "");
    EXPECT_DEATH(isotherm_2.Rgas(       0.0);, "");

}

int main(int argc, char **argv)
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS(); 
}
