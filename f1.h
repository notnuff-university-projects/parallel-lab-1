#ifndef F1_H
#define F1_H

#include "data.h"
#include "tthread.h"

// Клас для обчислення функції F1: d = (B*C) + (A*B) +(C*(B*(MA*ME)))
class F1 : public TThread {
public:
    F1(Data* data);
    const std::vector<double>& getResult() const { return result; }

protected:
    void execute() override;

private:
    Data* data;
    std::vector<double> result;
};

#endif //F1_H
