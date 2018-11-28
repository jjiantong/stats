/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

#include "stats.hpp"
#include "../stats_tests.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double mu = 1;
    double sigma = 2;

    std::cout << "\n*** dnorm: begin tests. ***\n" << std::endl;

    // x = 2
    double x_1 = 2;
    double val_1 = 0.17603266;
    double dens_1 = stats::dnorm(x_1,mu,sigma);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dnorm(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    double x_2 = 1;
    double val_2 = -1.612085;
    double dens_2 = stats::dnorm(x_2,mu,sigma,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dnorm(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** dnorm: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** dnorm: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

    std::vector<double> x_vec = {0.0, 1.0, 2.0};
    std::vector<double> val_vec = stats::dnorm(x_vec,1.0,2.0,false);

    for (int i=0; i < 3; ++i) {
        std::cout << "val[" << i << "] = " << val_vec[i] << "\n";
    }

#ifdef STATS_TEST_MAT
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 1.5;

    stats::dnorm(x_mat,mu,sigma);
    stats::dnorm(x_mat,mu,sigma,true);
#endif

    // arma::mat norm_pdf_vals = stats::dnorm(arma::ones(10,20),1.0,2.0);
    // norm_pdf_vals = stats::dnorm(arma::zeros(10,20),1.0,2.0);

    return 0;
}
