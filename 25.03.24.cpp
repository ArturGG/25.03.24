#include <iostream>
#include <cmath>
#include <cassert>

class DumplingFactory {
public:
    DumplingFactory(double dailyOutput, int shifts, int hours, double qProduction, double qDough, double qFilling, double doughRatio)
        : P(dailyOutput), N(shifts), t(hours), q_production(qProduction), q_dough(qDough), q_filling(qFilling), a_dough(doughRatio) {
        assert(N > 0 && t > 0);
        calculate();
    }

    void displayProductionNumbers() const {
        std::cout << "Calculating... " << std::endl << std::endl;
        std::cout << "Production units required: " << specialRound(n_production) << std::endl;
        std::cout << "Dough units required: " << specialRound(n_dough) << std::endl;
        std::cout << "Filling units required: " << specialRound(n_filling) << std::endl;
    }

private:
    double P, N, t;
    double q_production, q_dough, q_filling, a_dough;
    double n_production, n_dough, n_filling;

    void calculate() {
        double Q_production = P / (N * t);
        n_production = Q_production / q_production;
        double Q_dough = a_dough * Q_production;
        n_dough = Q_dough / q_dough;
        double Q_filling = (1 - a_dough) * Q_production;
        n_filling = Q_filling / q_filling;
    }

    int specialRound(double value) const {
        double fractionalPart = value - static_cast<int>(value);
        if (fractionalPart > 0.01) {
            return std::ceil(value);
        }
        else {
            return static_cast<int>(value);
        }
    }
};

void get_input(double& P, double& N, double& t, double& qp, double& qt, double& qf, double& at)
{
    setlocale(0, "rus");
    //float P, t, at, qp, qt, qf, Qp, Qt, Qf, np, nt, nf;
    std::cout << "Введите суточную норму: ";
    std::cin >> P;
    std::cout << "Введите колличество смен: ";
    std::cin >> N;
    if (N > 2 && N < 0) {
        std::cout << "Превышено возможное число смен ";
        return;
    }
    std::cout << "Введите продолжительность смены: ";
    std::cin >> t;
    if (t > 12 && t < 0) {
        std::cout << "Превышена продолжительность смены ";
        return;
    }
    std::cout << "Введите производительность пельменного автомата: ";
    std::cin >> qp;
    std::cout << "Введите производительность тестомесителя: ";
    std::cin >> qt;
    std::cout << "Введите производительность куттера: ";
    std::cin >> qf;
    std::cout << "Введите массовую долю теста: ";
    std::cin >> at;
    if (at > 0.9 && at < 0.1) {
        std::cout << "Не допустимое значение доли теста ";
        return;
    }
    //Qp = P / (N * t);
    //np = floor(Qp / qp) + 1;
    //cout << "Необходимое колличество пельменных автоматов " << np;
}

int main() {
    std::cout << "Welcome to the Dumpling Factory Production Calculator!\n";
    std::cout << "Please enter the following parameters:\n";

    

    double P, N, t, q_production, q_dough, q_filling, a_dough;

    get_input(P, N, t, q_production, q_dough, q_filling, a_dough);

    /*std::cout << "Daily output (P): ";
    std::cin >> P;
    std::cout << "Number of shifts (N): ";
    std::cin >> N;
    std::cout << "Hours per shift (t): ";
    std::cin >> t;
    std::cout << "Productivity of production machine (q_production): ";
    std::cin >> q_production;
    std::cout << "Productivity of dough machine (q_dough): ";
    std::cin >> q_dough;
    std::cout << "Productivity of filling machine (q_filling): ";
    std::cin >> q_filling;
    std::cout << "Dough ratio (a_dough), in decimal form (e.g., 0.5 for 50%): ";
    std::cin >> a_dough;*/

    DumplingFactory factory(P, N, t, q_production, q_dough, q_filling, a_dough);
    factory.displayProductionNumbers();

    return 0;
}
