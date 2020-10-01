
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

#include "../../read_write_wav.h"

using namespace std;

//helper functions
float midi2freq(int m)
{
    return 440*pow(2,(m-69.0f)/12.0f);
}

float freq2midi(float freq)
{
    return 12*log2( freq/440) + 69;
}
//


class SoundProcessor  
{
    public:

        virtual void process(float*, int)
        {
        }
};


class SineOscillator : public SoundProcessor
{
    public: 

        float freq;
        float amp;
        float Fs;


        SineOscillator(int nota_midi, float _amp, float _Fs)
        {
            freq = midi2freq(nota_midi);
            amp = _amp;
            Fs = _Fs;
        }

        ~SineOscillator()
        {
        }   

        void process(float* audio_buffer, int buffer_len) 
        {
            cout << "sine class -> call process: "<<  buffer_len << " amp: "<<  amp << " freq: "<< freq << "  Fs: " << Fs << endl;
            for (int n=0; n<buffer_len; n++)
            {
                //audio_buffer[n] += amp * sin(2*M_PI*freq*(((float)n)/Fs)); 
                audio_buffer[n] = amp * sin(2*M_PI*freq*(((float)n)/Fs)); 
            }
        }

};

class MusicNote
{
    public:
        float start_time; // pos in seconds
        float end_time; // pos in seconds
        SoundProcessor* sp;

    MusicNote(SoundProcessor *o, float s, float e):sp(o), start_time(s), end_time(e)
    {
    }


};

int main(int c, char** argv)
{
    const float Fs = 44100; //sample rate (samples /second)
    float *audio_buffer;
    vector<MusicNote> notes;
    float* audio_buffer_file;
    int buffer_len;
    int sample_rate;
    int n_channels;

    //===============================
    SineOscillator* s1 = new SineOscillator(57, 0.3, Fs);
    MusicNote m1(s1, 0.0f, 0.3f);
    notes.push_back(m1);

    SineOscillator* s2 = new SineOscillator(60, 0.3, Fs);
    MusicNote m2(s2, 0.25f, 0.6f);
    notes.push_back(m2);

    SineOscillator* s3 = new SineOscillator(62, 0.3, Fs);
    MusicNote m3(s3, 0.5f, 1.1f);
    notes.push_back(m3);

    SineOscillator* s4 = new SineOscillator(62, 0.3, Fs);
    MusicNote m4(s4, 1.0f, 1.6f);
    notes.push_back(m4);

    SineOscillator* s5 = new SineOscillator(62, 0.3, Fs);
    MusicNote m5(s5, 1.5f, 1.8f);
    notes.push_back(m5);

    SineOscillator* s6 = new SineOscillator(64, 0.3, Fs);
    MusicNote m6(s6, 1.75f, 2.05f);
    notes.push_back(m6);

    SineOscillator* s7 = new SineOscillator(65, 0.3, Fs);
    MusicNote m7(s7, 2.0f, 2.6f);
    notes.push_back(m7);

    SineOscillator* s8 = new SineOscillator(65, 0.3, Fs);
    MusicNote m8(s8, 2.5f, 3.05f);
    notes.push_back(m8);

    SineOscillator* s9 = new SineOscillator(65, 0.3, Fs);
    MusicNote m9(s9, 3.0f, 3.25f);
    notes.push_back(m9);

    SineOscillator* s10 = new SineOscillator(67, 0.3, Fs);
    MusicNote m10(s10, 3.25f, 3.5f);
    notes.push_back(m10);

    SineOscillator* s11 = new SineOscillator(64, 0.3, Fs);
    MusicNote m11(s11, 3.5f, 4.0f);
    notes.push_back(m11);

    SineOscillator* s12 = new SineOscillator(64, 0.3, Fs);
    MusicNote m12(s12, 4.0f, 4.5f);
    notes.push_back(m12);

    SineOscillator* s13 = new SineOscillator(62, 0.3, Fs);
    MusicNote m13(s13, 4.5f, 4.75f);
    notes.push_back(m13);

    SineOscillator* s14 = new SineOscillator(60, 0.3, Fs);
    MusicNote m14(s14, 4.75f, 5.0f);
    notes.push_back(m14);

    SineOscillator* s15 = new SineOscillator(60, 0.3, Fs);
    MusicNote m15(s15, 5.0f, 5.25f);
    notes.push_back(m15);

    SineOscillator* s16 = new SineOscillator(62, 0.3, Fs);
    MusicNote m16(s16, 5.25f, 6.0f);
    notes.push_back(m16);

    SineOscillator* s17 = new SineOscillator(57, 0.3, Fs);
    MusicNote m17(s17, 6.0f, 6.25f);
    notes.push_back(m17);

    SineOscillator* s18 = new SineOscillator(60, 0.3, Fs);
    MusicNote m18(s18, 6.25f, 6.5f);
    notes.push_back(m18);

    SineOscillator* s19 = new SineOscillator(62, 0.3, Fs);
    MusicNote m19(s19, 6.5f, 7.0f);
    notes.push_back(m19);

    SineOscillator* s20 = new SineOscillator(62, 0.3, Fs);
    MusicNote m20(s20, 7.0f, 7.5f);
    notes.push_back(m20);

    SineOscillator* s21 = new SineOscillator(62, 0.3, Fs);
    MusicNote m21(s21, 7.5f, 7.75f);
    notes.push_back(m21);

    SineOscillator* s22 = new SineOscillator(64, 0.3, Fs);
    MusicNote m22(s22, 7.75f, 8.0f);
    notes.push_back(m22);

    SineOscillator* s23 = new SineOscillator(65, 0.3, Fs);
    MusicNote m23(s23, 8.0f, 8.5f);
    notes.push_back(m23);

    SineOscillator* s24 = new SineOscillator(65, 0.3, Fs);
    MusicNote m24(s24, 8.5f, 9.0f);
    notes.push_back(m24);

    SineOscillator* s25 = new SineOscillator(65, 0.3, Fs);
    MusicNote m25(s25, 9.0f, 9.25f);
    notes.push_back(m25);

    SineOscillator* s26 = new SineOscillator(67, 0.3, Fs);
    MusicNote m26(s26, 9.25f, 9.5f);
    notes.push_back(m26);

    SineOscillator* s27 = new SineOscillator(64, 0.3, Fs);
    MusicNote m27(s27, 9.5f, 10.0f);
    notes.push_back(m27);

    SineOscillator* s28 = new SineOscillator(64, 0.3, Fs);
    MusicNote m28(s28, 10.0f, 10.5f);
    notes.push_back(m28);

    SineOscillator* s29 = new SineOscillator(62, 0.3, Fs);
    MusicNote m29(s29, 10.5f, 10.75f);
    notes.push_back(m29);

    SineOscillator* s30 = new SineOscillator(60, 0.3, Fs);
    MusicNote m30(s30, 10.75f, 11.0f);
    notes.push_back(m30);

    SineOscillator* s31 = new SineOscillator(62, 0.3, Fs);
    MusicNote m31(s31, 11.0f, 11.75f);
    notes.push_back(m31);

    //===============================
    // get max signal duration
    int max_pos = 0;
    for (int k=0; k<notes.size(); k++)
    {
        max_pos = std::max((float)max_pos, (float)round(notes[k].end_time*Fs));
    }

    n_channels = read_wave_file("Pirates of the Caribbean.wav", audio_buffer_file, &buffer_len, &sample_rate);

    long int tam = max_pos+buffer_len;

    cout << "Tam: " << tam << endl;

    audio_buffer = new float[tam];
    memset(audio_buffer, 0, max_pos+buffer_len);

    cout << "maxPos: " << max_pos <<  endl;
    // write the notes into the audio buffer
    for (int k=0; k<notes.size(); k++)
    {
        int startPos = notes[k].start_time*Fs;
        int endPos = notes[k].end_time*Fs;
        notes[k].sp->process(audio_buffer + startPos, endPos-startPos);
    }

    int startPos = notes[30].end_time*Fs;
    std::copy(audio_buffer_file, audio_buffer_file+buffer_len, audio_buffer+startPos);

    // ============================
    // save output wave
    string wav_name = "piratemelody.wav";
    write_wave_file (wav_name.c_str(), audio_buffer, tam, Fs);
    cout << "done." << endl;
    delete [] audio_buffer;
    return 0;
}