#ifndef AI_H
#define AI_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cmath>

using namespace std;

class Neuron;

struct Connection
{
    double weight;
    double deltaweight;
};

typedef vector<Neuron> Layer;

class Neuron
{
    public:
        Neuron(unsigned numOutputs);
        void setOutputVal(double val) { m_outputVal = val; }
        double getOutputVal() { return m_outputVal; }
        void feedForward(const Layer &layer);
        void calculateInputGradients(double targetVal);
    private:
        double m_outputVal;
        vector<Connection> m_inputWeights;
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        static double randomWeight(){ return rand() / double(RAND_MAX); }
};

class Net
{
    public:
        Net(const vector<unsigned> &topology);
        void FeedForward(const vector<double> &inputVals);
        void BackProp(const vector<double> &targetVals);
        void GetResults(vector<double> &resultVals){};

    private:
        vector<Layer> m_layers; // m_layers[num_layer][num_neuron]
};

#endif // AI_H
