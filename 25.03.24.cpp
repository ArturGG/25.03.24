#include <iostream>
#include <cassert>

class DumplingFactory {
public:
    DumplingFactory(double dailyOutput, int shifts, int hours, double qProduction, double qDough, double qFilling, double doughRatio)
        : P(dailyOutput), N(shifts), t(hours), q_production(qProduction), q_dough(qDough), q_filling(qFilling), a_dough(doughRatio) {
        assert(N > 0 && t > 0); // Проверка на корректность входных данных
        calculate();
    }

    void displayProductionNumbers() const {
        std::cout << "Production units required: " << n_production << std::endl;
        std::cout << "Dough units required: " << n_dough << std::endl;
        std::cout << "Filling units required: " << n_filling << std::endl;
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
};

int main() {
    double P, N, t, q_production, q_dough, q_filling, a_dough;
    std::cout << "Enter daily output, number of shifts, hours per shift, productivity of production, dough, filling machines and dough ratio respectively:\n";
    std::cin >> P >> N >> t >> q_production >> q_dough >> q_filling >> a_dough;

    DumplingFactory factory(P, N, t, q_production, q_dough, q_filling, a_dough);
    factory.displayProductionNumbers();

    return 0;
}