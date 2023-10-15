#include "button.hpp"

bool Button::debounce()
{
    do
    {
       if (getSample() == m_lastSample)
        {
            ++m_consecutiveSamples;
        }
        else
        {
            m_consecutiveSamples = 0;
            m_lastSample = !m_lastSample;
        }
    }

    while (m_consecutiveSamples < DEBOUNCE_SAMPLE_MIN);
    setStatus(m_lastSample);
    return m_status;
}

void Button::setStatus(bool status)
{
    m_status = status;
}

bool Button::getSample()
{
    return (*m_sampleData &= m_dataBit);
}

    
