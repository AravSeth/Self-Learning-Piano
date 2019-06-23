#define motor_PWM 38# define motor_Clockwise 36# define motor_Counterclockwise 34

int pot = A0;
int gameNotes[3] = {
    3,
    4,
    5
};
int userNotes[3] = {};
int gameNotes2[6] = {
    3,
    5,
    6,
    8,
    9,
    10
};
int userNotes2[6] = {};
int gameNotes3[8] = {
    10,
    8,
    9,
    7,
    6,
    5,
    3,
    4
};
int userNotes3[8] = {};
int t = 15;
int gameState = 0;
int speaker = 15;
int an = 956;
int bn = 1014;
int cn = 1136;
int dn = 1275;
int en = 1432;
int fn = 1519;
int gn = 1700;
int hn = 1915;
int a = 3;
int b = 4;
int c = 5;
int d = 6;
int e = 7;
int f = 8;
int g = 9;
int h = 10;
int m1s;
int m2s;
int mode1 = 24;
int mode2 = 25;
int as;
int bs;
int cs;
int ds;
int es;
int fs;
int gs;
int hs;
int is;
int al = 16;
int bl = 17;
int cl = 18;
int dl = 19;
int el = 20;
int fl = 21;
int gl = 22;
int hl = 23;
int potentiometer = A0;
int potValue = 0;


void setup() {
    Serial.begin(9600);
    pinMode(a, INPUT);
    pinMode(b, INPUT);
    pinMode(c, INPUT);
    pinMode(d, INPUT);
    pinMode(e, INPUT);
    pinMode(f, INPUT);
    pinMode(g, INPUT);
    pinMode(h, INPUT);
    pinMode(al, OUTPUT);
    pinMode(bl, OUTPUT);
    pinMode(cl, OUTPUT);
    pinMode(dl, OUTPUT);
    pinMode(el, OUTPUT);
    pinMode(fl, OUTPUT);
    pinMode(gl, OUTPUT);
    pinMode(hl, OUTPUT);
    pinMode(speaker, OUTPUT);
    pinMode(motor_PWM, OUTPUT);
    pinMode(motor_Clockwise, OUTPUT);
    pinMode(motor_Counterclockwise, OUTPUT);
    pinMode(mode1, INPUT);
    pinMode(mode2, INPUT);
}



bool compareArrays() {
    for (int sp = 0; sp < 3; sp++) {
        if (userNotes[sp] != gameNotes[sp]) {
            return false;
        }
    }
    return true;
}

bool compareArrays2() {
    for (int sp = 0; sp < 6; sp++) {
        if (userNotes2[sp] != gameNotes2[sp]) {
            return false;
        }
    }
    return true;
}

bool compareArrays3() {
    for (int sp = 0; sp < 8; sp++) {
        if (userNotes3[sp] != gameNotes3[sp]) {
            return false;
        }
    }
    return true;
}



void loop() {
    potValue = analogRead(potentiometer);
    delay(10);
    pinMode(motor_PWM, 255);

    m1s = digitalRead(mode1);
    if (m1s == HIGH) {
        gameState = gameState + 1;
    }
    if (gameState > 0) {
        function_slev1();
        delay(100);
    } else {
        as = digitalRead(a);
        if (as == HIGH) {
            digitalWrite(al, HIGH);
            tone(speaker, an);
            delay(t);
        } else {
            digitalWrite(al, LOW);
        }



        bs = digitalRead(b);
        if (bs == HIGH) {
            digitalWrite(bl, HIGH);
            tone(speaker, bn);
            delay(t);
        } else {
            digitalWrite(bl, LOW);
        }



        cs = digitalRead(c);
        if (cs == HIGH) {
            digitalWrite(cl, HIGH);
            tone(speaker, cn);
            delay(t);
        } else {
            digitalWrite(cl, LOW);
        }


        ds = digitalRead(d);
        if (ds == HIGH) {
            digitalWrite(dl, HIGH);
            tone(speaker, dn);
            delay(t);
        } else {
            digitalWrite(dl, LOW);
        }



        es = digitalRead(e);
        if (es == HIGH) {
            digitalWrite(el, HIGH);
            tone(speaker, en);
            delay(t);
        } else {
            digitalWrite(el, LOW);
        }




        fs = digitalRead(f);
        if (fs == HIGH) {
            digitalWrite(fl, HIGH);
            tone(speaker, fn);
            delay(t);
        } else {
            digitalWrite(fl, LOW);
        }


        gs = digitalRead(g);
        if (gs == HIGH) {
            digitalWrite(gl, HIGH);
            tone(speaker, gn);
            delay(t);
        } else {
            digitalWrite(gl, LOW);
        }




        hs = digitalRead(h);
        if (hs == HIGH) {
            digitalWrite(hl, HIGH);
            tone(speaker, hn);
            delay(t);
        } else {
            digitalWrite(hl, LOW);
        }

        if (as == LOW, bs == LOW, cs == LOW, ds == LOW, es == LOW, fs == LOW, gs == LOW, hs == LOW and gameState < 1) {
            noTone(speaker);
            digitalWrite(al, LOW);
            digitalWrite(bl, LOW);
            digitalWrite(cl, LOW);
            digitalWrite(dl, LOW);
            digitalWrite(el, LOW);
            digitalWrite(fl, LOW);
            digitalWrite(gl, LOW);
            digitalWrite(hl, LOW);
        }
    }
}


void setAllButtons() {
    as = digitalRead(a);
    bs = digitalRead(b);
    cs = digitalRead(c);
    ds = digitalRead(d);
    es = digitalRead(e);
    fs = digitalRead(f);
    gs = digitalRead(g);
    hs = digitalRead(h);
    m2s = digitalRead(mode2);

}

void function_slev2() {
    playSound(an, al, 300);
    playSound(cn, cl, 300);
    playSound(dn, dl, 300);
    playSound(fn, fl, 500);
    playSound(gn, gl, 500);
    playSound(hn, hl, 500);
    function_lev2();
}


void function_lev3() {
    for (int ii = 0; ii <= 8; ii++) {
        Serial.println(ii);
        for (int jj = 0; jj < 8; jj++) {
            Serial.println(jj);
            setAllButtons();
            while (as == LOW && bs == LOW && cs == LOW && ds == LOW && es == LOW && fs == LOW && gs == LOW && hs == LOW) {
                noTone(speaker);
                setAllButtons();
                delay(10);
                if (m2s == HIGH) {
                    gameState = 0;
                    return loop();
                }
            }

            if (as == HIGH) {
                userNotes3[jj] = 3;
                playSound(an, al, 500);
            } else if (bs == HIGH) {
                userNotes3[jj] = 4;
                playSound(bn, bl, 500);
            } else if (cs == HIGH) {
                userNotes3[jj] = 5;
                playSound(cn, cl, 500);
            } else if (ds == HIGH) {
                userNotes3[jj] = 6;
                playSound(dn, dl, 500);
            } else if (es == HIGH) {
                userNotes3[jj] = 7;
                playSound(en, el, 500);
            } else if (fs == HIGH) {
                userNotes3[jj] = 8;
                playSound(fn, fl, 500);
            } else if (gs == HIGH) {
                userNotes3[jj] = 9;
                playSound(gn, gl, 500);
            } else if (hs == HIGH) {
                userNotes3[jj] = 10;
                playSound(hn, hl, 500);
            }
            Serial.println(userNotes3[jj]);
            while (as == HIGH || bs == HIGH || cs == HIGH || ds == HIGH || es == HIGH || fs == HIGH || gs == HIGH || hs == HIGH) {
                setAllButtons();
                delay(10);
            }


        }
        if (compareArrays3()) {
            noTone(speaker);
            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, HIGH);
            delay(700);

            analogWrite(motor_PWM, 0);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(2000);

            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, HIGH);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(700);

            analogWrite(motor_PWM, 0);
            return loop();
        } else {
            noTone(speaker);
            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, HIGH);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(700);

            analogWrite(motor_PWM, 0);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(1000);

            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, HIGH);
            delay(700);

            analogWrite(motor_PWM, 0);
            gameState = 0;
            return loop();

        }
    }
}




void function_lev2() {
    for (int ii = 0; ii <= 6; ii++) {
        Serial.println(ii);
        for (int jj = 0; jj < 6; jj++) {
            Serial.println(jj);
            setAllButtons();
            while (as == LOW && bs == LOW && cs == LOW && ds == LOW && es == LOW && fs == LOW && gs == LOW && hs == LOW) {
                noTone(speaker);
                setAllButtons();
                delay(10);
                if (m2s == HIGH) {
                    gameState = 0;
                    return loop();
                }
            }

            if (as == HIGH) {
                userNotes2[jj] = 3;
                playSound(an, al, 500);
            } else if (bs == HIGH) {
                userNotes2[jj] = 4;
                playSound(bn, bl, 500);
            } else if (cs == HIGH) {
                userNotes2[jj] = 5;
                playSound(cn, cl, 500);
            } else if (ds == HIGH) {
                userNotes2[jj] = 6;
                playSound(dn, dl, 500);
            } else if (es == HIGH) {
                userNotes2[jj] = 7;
                playSound(en, el, 500);
            } else if (fs == HIGH) {
                userNotes2[jj] = 8;
                playSound(fn, fl, 500);
            } else if (gs == HIGH) {
                userNotes2[jj] = 9;
                playSound(gn, gl, 500);
            } else if (hs == HIGH) {
                userNotes2[jj] = 10;
                playSound(hn, hl, 500);
            }
            Serial.println(userNotes2[jj]);
            while (as == HIGH || bs == HIGH || cs == HIGH || ds == HIGH || es == HIGH || fs == HIGH || gs == HIGH || hs == HIGH) {
                setAllButtons();
                delay(10);
            }


        }
        if (compareArrays2()) {
            noTone(speaker);
            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, HIGH);
            delay(700);

            analogWrite(motor_PWM, 0);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(2000);

            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, HIGH);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(700);

            analogWrite(motor_PWM, 0);
            function_slev3();
        } else {
            noTone(speaker);
            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, HIGH);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(700);

            analogWrite(motor_PWM, 0);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(1000);

            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, HIGH);
            delay(700);

            analogWrite(motor_PWM, 0);
            gameState = 0;
            return loop();

        }
    }
}

void function_lev1() {
    for (int ii = 0; ii <= 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
            setAllButtons();
            while (as == LOW && bs == LOW && cs == LOW && ds == LOW && es == LOW && fs == LOW && gs == LOW && hs == LOW) {
                noTone(speaker);
                setAllButtons();
                delay(10);
                if (m2s == HIGH) {
                    gameState = 0;
                    return loop();
                }
            }
            if (as == HIGH) {
                userNotes[jj] = 3;
                playSound(an, al, 500);
            } else if (bs == HIGH) {
                userNotes[jj] = 4;
                playSound(bn, bl, 500);
            } else if (cs == HIGH) {
                userNotes[jj] = 5;
                playSound(cn, cl, 500);
            } else if (ds == HIGH) {
                userNotes[jj] = 6;
                playSound(dn, dl, 500);
            } else if (es == HIGH) {
                userNotes[jj] = 7;
                playSound(en, el, 500);
            } else if (fs == HIGH) {
                userNotes[jj] = 8;
                playSound(fn, fl, 500);
            } else if (gs == HIGH) {
                userNotes[jj] = 9;
                playSound(gn, gl, 500);
            } else if (hs == HIGH) {
                userNotes[jj] = 10;
                playSound(hn, hl, 500);
            }
            while (as == HIGH || bs == HIGH || cs == HIGH || ds == HIGH || es == HIGH || fs == HIGH || gs == HIGH || hs == HIGH) {
                setAllButtons();
                delay(10);
            }


        }
        if (compareArrays()) {
            noTone(speaker);
            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, HIGH);
            delay(700);

            analogWrite(motor_PWM, 0);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(2000);

            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, HIGH);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(700);

            analogWrite(motor_PWM, 0);
            function_slev2();
        } else {
            noTone(speaker);
            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, HIGH);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(700);

            analogWrite(motor_PWM, 0);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, LOW);
            delay(1000);

            analogWrite(motor_PWM, 255);
            digitalWrite(motor_Clockwise, LOW);
            digitalWrite(motor_Counterclockwise, HIGH);
            delay(700);

            analogWrite(motor_PWM, 0);
            gameState = 0;
            return loop();

        }
    }
}

void playSound(int note, int led, int t2) {
    tone(speaker, note);
    digitalWrite(led, HIGH);
    delay(t2);
    digitalWrite(led, LOW);
}

void function_slev3() {
    playSound(hn, hl, 500);
    playSound(fn, fl, 200);
    playSound(gn, gl, 200);
    playSound(en, el, 300);
    playSound(dn, dl, 300);
    playSound(cn, cl, 300);
    playSound(an, al, 250);
    playSound(bn, bl, 250);
    function_lev3();
}

void function_slev1() {
    playSound(an, al, 500);
    playSound(bn, bl, 500);
    playSound(cn, cl, 500);
    function_lev1();
}
