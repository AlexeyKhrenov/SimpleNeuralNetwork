Neuron::Neuron(unsigned numOutputs)
{
    for(int c = 0; c < numOutputs; ++c)
    {
        m_inputWeights.push_back(Connection());
        m_inputWeights.back().weight = randomWeight();
    }
}

double Neuron::transferFunction(double x)
{
    // approximation
    return tanh(x);
}

double Neuron::transferFunctionDerivative(double x){
    return 1.0 - x * x;
}

void Neuron::feedForward(const Layer &layer)
{
    double sum = 0.0;
    for(int i = 0; i < layer.size(); i++)
    {
        sum += layer[i].m_outputVal * m_inputWeights[i].weight;
    }

    m_outputVal = Neuron::transferFunction(sum);
}

void Neuron::calculateInputGradients(double targetValue)
{

}

Net::Net(const vector<unsigned> &topology)
{
    unsigned numLayers = topology.size();

    for(int i = 0; i < topology.size(); i++)
    {
        unsigned numOutputs = i == topology.size() - 1 ? 0 : topology[i + 1];

        m_layers.push_back(Layer());
        for(int j = 0; j <= topology[i]; j++)
        {
            m_layers[i].push_back(Neuron(numOutputs));
        }
    }
}

void Net::FeedForward(const vector<double> &inputVals)
{
    assert(inputVals.size() == m_layers[0].size() - 1);

    // assign input values into the input neurons
    for(int i = 0; i < inputVals.size(); i++){
        m_layers[0][i].setOutputVal(inputVals[i]);
    }

    // forward-propagation
    for(int i = 1; i < m_layers.size(); ++i)
    {
        Layer &prev_layer = m_layers[i - 1];
        for(int j = 0; j < m_layers[i].size() - 1; j++){
            m_layers[i][j].feedForward(prev_layer);
        }
    }
}

void Net::BackProp(const vector<double> &targetVals)
{
    // calculate overall network error (RMS)
    Layer &outputLayer = m_layers.back();
    double error = 0.0;

    for(int i = 0; i < outputLayer.size() - 1; i++)
    {
        double delta = outputLayer[i].getOutputVal() - targetVals[i];
        error += delta * delta;
    }

    error /= outputLayer.size() - 1;
    error = sqrt(error);

    // calculate input layer gradients
    for(int i = 1; )

    // calculate output layer gradients on hidden layer

    // update connection weights
}
