#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <stdint.h>

#define DEBOUNCE_SAMPLE_MIN 3
#define ACTIVE_HI 1
#define ACTIVE_LO 0


class Button
{
    bool m_activeState;
    bool m_status;
    bool m_lastSample;
    volatile uint32_t* m_sampleData;
    const uint16_t m_dataBit;
    uint8_t m_consecutiveSamples;

    public:

    Button(bool activeState = 0, volatile uint32_t* sampleData = nullptr, const uint16_t dataBit = 0x00)
        : m_activeState{activeState}, m_status{!activeState}, m_lastSample{!activeState}, m_sampleData{sampleData}, m_dataBit{dataBit}{}

    bool debounce();

    void setStatus(bool status);

    bool getSample();

};

#endif
