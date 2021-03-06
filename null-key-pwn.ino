/* Arduino USB HID Demo by _null_ */

#define PIN_LED 13

uint8_t buf[8] = { 0 };	/* Keyboard report buffer */

void setup();
void loop();

#define MODIFIERKEY_CTRL        ( 0x01 | 0x8000 )
#define MODIFIERKEY_SHIFT       ( 0x02 | 0x8000 )
#define MODIFIERKEY_ALT         ( 0x04 | 0x8000 )
#define MODIFIERKEY_GUI         ( 0x08 | 0x8000 )
#define MODIFIERKEY_LEFT_CTRL   ( 0x01 | 0x8000 )
#define MODIFIERKEY_LEFT_SHIFT  ( 0x02 | 0x8000 )
#define MODIFIERKEY_LEFT_ALT    ( 0x04 | 0x8000 )
#define MODIFIERKEY_LEFT_GUI    ( 0x08 | 0x8000 )
#define MODIFIERKEY_RIGHT_CTRL  ( 0x10 | 0x8000 )
#define MODIFIERKEY_RIGHT_SHIFT ( 0x20 | 0x8000 )
#define MODIFIERKEY_RIGHT_ALT   ( 0x40 | 0x8000 )
#define MODIFIERKEY_RIGHT_GUI   ( 0x80 | 0x8000 )

#define KEY_MEDIA_VOLUME_INC    0x01
#define KEY_MEDIA_VOLUME_DEC    0x02
#define KEY_MEDIA_MUTE          0x04
#define KEY_MEDIA_PLAY_PAUSE    0x08
#define KEY_MEDIA_NEXT_TRACK    0x10
#define KEY_MEDIA_PREV_TRACK    0x20
#define KEY_MEDIA_STOP          0x40
#define KEY_MEDIA_EJECT         0x80

#define KEY_A           ( 4   | 0x4000 )
#define KEY_B           ( 5   | 0x4000 )
#define KEY_C           ( 6   | 0x4000 )
#define KEY_D           ( 7   | 0x4000 )
#define KEY_E           ( 8   | 0x4000 )
#define KEY_F           ( 9   | 0x4000 )
#define KEY_G           ( 10  | 0x4000 )
#define KEY_H           ( 11  | 0x4000 )
#define KEY_I           ( 12  | 0x4000 )
#define KEY_J           ( 13  | 0x4000 )
#define KEY_K           ( 14  | 0x4000 )
#define KEY_L           ( 15  | 0x4000 )
#define KEY_M           ( 16  | 0x4000 )
#define KEY_N           ( 17  | 0x4000 )
#define KEY_O           ( 18  | 0x4000 )
#define KEY_P           ( 19  | 0x4000 )
#define KEY_Q           ( 20  | 0x4000 )
#define KEY_R           ( 21  | 0x4000 )
#define KEY_S           ( 22  | 0x4000 )
#define KEY_T           ( 23  | 0x4000 )
#define KEY_U           ( 24  | 0x4000 )
#define KEY_V           ( 25  | 0x4000 )
#define KEY_W           ( 26  | 0x4000 )
#define KEY_X           ( 27  | 0x4000 )
#define KEY_Y           ( 28  | 0x4000 )
#define KEY_Z           ( 29  | 0x4000 )
#define KEY_1           ( 30  | 0x4000 )
#define KEY_2           ( 31  | 0x4000 )
#define KEY_3           ( 32  | 0x4000 )
#define KEY_4           ( 33  | 0x4000 )
#define KEY_5           ( 34  | 0x4000 )
#define KEY_6           ( 35  | 0x4000 )
#define KEY_7           ( 36  | 0x4000 )
#define KEY_8           ( 37  | 0x4000 )
#define KEY_9           ( 38  | 0x4000 )
#define KEY_0           ( 39  | 0x4000 )
#define KEY_ENTER       ( 40  | 0x4000 )
#define KEY_ESC         ( 41  | 0x4000 )
#define KEY_BACKSPACE   ( 42  | 0x4000 )
#define KEY_TAB         ( 43  | 0x4000 )
#define KEY_SPACE       ( 44  | 0x4000 )
#define KEY_MINUS       ( 45  | 0x4000 )
#define KEY_EQUAL       ( 46  | 0x4000 )
#define KEY_LEFT_BRACE  ( 47  | 0x4000 )
#define KEY_RIGHT_BRACE ( 48  | 0x4000 )
#define KEY_BACKSLASH   ( 49  | 0x4000 )
#define KEY_NON_US_NUM  ( 50  | 0x4000 )
#define KEY_SEMICOLON   ( 51  | 0x4000 )
#define KEY_QUOTE       ( 52  | 0x4000 )
#define KEY_TILDE       ( 53  | 0x4000 )
#define KEY_COMMA       ( 54  | 0x4000 )
#define KEY_PERIOD      ( 55  | 0x4000 )
#define KEY_SLASH       ( 56  | 0x4000 )
#define KEY_CAPS_LOCK   ( 57  | 0x4000 )
#define KEY_F1          ( 58  | 0x4000 )
#define KEY_F2          ( 59  | 0x4000 )
#define KEY_F3          ( 60  | 0x4000 )
#define KEY_F4          ( 61  | 0x4000 )
#define KEY_F5          ( 62  | 0x4000 )
#define KEY_F6          ( 63  | 0x4000 )
#define KEY_F7          ( 64  | 0x4000 )
#define KEY_F8          ( 65  | 0x4000 )
#define KEY_F9          ( 66  | 0x4000 )
#define KEY_F10         ( 67  | 0x4000 )
#define KEY_F11         ( 68  | 0x4000 )
#define KEY_F12         ( 69  | 0x4000 )
#define KEY_PRINTSCREEN ( 70  | 0x4000 )
#define KEY_SCROLL_LOCK ( 71  | 0x4000 )
#define KEY_PAUSE       ( 72  | 0x4000 )
#define KEY_INSERT      ( 73  | 0x4000 )
#define KEY_HOME        ( 74  | 0x4000 )
#define KEY_PAGE_UP     ( 75  | 0x4000 )
#define KEY_DELETE      ( 76  | 0x4000 )
#define KEY_END         ( 77  | 0x4000 )
#define KEY_PAGE_DOWN   ( 78  | 0x4000 )
#define KEY_RIGHT       ( 79  | 0x4000 )
#define KEY_LEFT        ( 80  | 0x4000 )
#define KEY_DOWN        ( 81  | 0x4000 )
#define KEY_UP          ( 82  | 0x4000 )
#define KEY_NUM_LOCK    ( 83  | 0x4000 )
#define KEYPAD_SLASH    ( 84  | 0x4000 )
#define KEYPAD_ASTERIX  ( 85  | 0x4000 )
#define KEYPAD_MINUS    ( 86  | 0x4000 )
#define KEYPAD_PLUS     ( 87  | 0x4000 )
#define KEYPAD_ENTER    ( 88  | 0x4000 )
#define KEYPAD_1        ( 89  | 0x4000 )
#define KEYPAD_2        ( 90  | 0x4000 )
#define KEYPAD_3        ( 91  | 0x4000 )
#define KEYPAD_4        ( 92  | 0x4000 )
#define KEYPAD_5        ( 93  | 0x4000 )
#define KEYPAD_6        ( 94  | 0x4000 )
#define KEYPAD_7        ( 95  | 0x4000 )
#define KEYPAD_8        ( 96  | 0x4000 )
#define KEYPAD_9        ( 97  | 0x4000 )
#define KEYPAD_0        ( 98  | 0x4000 )
#define KEYPAD_PERIOD   ( 99  | 0x4000 )
#define KEY_F13         ( 104 | 0x4000 )
#define KEY_F14         ( 105 | 0x4000 )
#define KEY_F15         ( 106 | 0x4000 )
#define KEY_F16         ( 107 | 0x4000 )
#define KEY_F17         ( 108 | 0x4000 )
#define KEY_F18         ( 109 | 0x4000 )
#define KEY_F19         ( 110 | 0x4000 )
#define KEY_F20         ( 111 | 0x4000 )
#define KEY_F21         ( 112 | 0x4000 )
#define KEY_F22         ( 113 | 0x4000 )
#define KEY_F23         ( 114 | 0x4000 )
#define KEY_F24         ( 115 | 0x4000 )


// for compatibility with Leonardo's slightly different names
#define KEY_UP_ARROW	KEY_UP
#define KEY_DOWN_ARROW	KEY_DOWN
#define KEY_LEFT_ARROW	KEY_LEFT
#define KEY_RIGHT_ARROW	KEY_RIGHT
#define KEY_RETURN	KEY_ENTER
#define KEY_LEFT_CTRL	MODIFIERKEY_LEFT_CTRL
#define KEY_LEFT_SHIFT	MODIFIERKEY_LEFT_SHIFT
#define KEY_LEFT_ALT	MODIFIERKEY_LEFT_ALT
#define KEY_LEFT_GUI	MODIFIERKEY_LEFT_GUI
#define KEY_RIGHT_CTRL	MODIFIERKEY_RIGHT_CTRL
#define KEY_RIGHT_SHIFT	MODIFIERKEY_RIGHT_SHIFT
#define KEY_RIGHT_ALT	MODIFIERKEY_RIGHT_ALT
#define KEY_RIGHT_GUI	MODIFIERKEY_RIGHT_GUI



void sendKey()
{
	Serial.write(buf, 8);	// Send keypress
	buf[0] = 0;
	buf[2] = 0;
	Serial.write(buf, 8);	// Release key
}

// Set mod to one of MOD_KEYs
void pressKey(char key, uint8_t mod = 0)
{
	if ( key >= 'A' && key <= 'Z' )
	{
		key = key - 'A' + 'a';
		mod = mod | MODIFIERKEY_SHIFT;
	}
	
	buf[0] = mod;
	
	// ALPHABETS
	if( key == 'a' ) buf[2] = KEY_A;
	else
	if( key == 'b' ) buf[2] = KEY_B;
	else
	if( key == 'c' ) buf[2] = KEY_C;
	else
	if( key == 'd' ) buf[2] = KEY_D;
	else
	if( key == 'e' ) buf[2] = KEY_E;
	else
	if( key == 'f' ) buf[2] = KEY_F;
	else
	if( key == 'g' ) buf[2] = KEY_G;
	else
	if( key == 'h' ) buf[2] = KEY_H;
	else
	if( key == 'i' ) buf[2] = KEY_I;
	else
	if( key == 'j' ) buf[2] = KEY_J;
	else
	if( key == 'k' ) buf[2] = KEY_K;
	else
	if( key == 'l' ) buf[2] = KEY_L;
	else
	if( key == 'm' ) buf[2] = KEY_M;
	else
	if( key == 'n' ) buf[2] = KEY_N;
	else
	if( key == 'o' ) buf[2] = KEY_O;
	else
	if( key == 'p' ) buf[2] = KEY_P;
	else
	if( key == 'q' ) buf[2] = KEY_Q;
	else
	if( key == 'r' ) buf[2] = KEY_R;
	else
	if( key == 's' ) buf[2] = KEY_S;
	else
	if( key == 't' ) buf[2] = KEY_T;
	else
	if( key == 'u' ) buf[2] = KEY_U;
	else
	if( key == 'v' ) buf[2] = KEY_V;
	else
	if( key == 'w' ) buf[2] = KEY_W;
	else
	if( key == 'x' ) buf[2] = KEY_X;
	else
	if( key == 'y' ) buf[2] = KEY_Y;
	else
	if( key == 'z' ) buf[2] = KEY_Z;
	// NUMBERS
	else
	if( key == '0' ) buf[2] = KEY_0;
	else
	if( key == '1' ) buf[2] = KEY_1;
	else
	if( key == '2' ) buf[2] = KEY_2;
	else
	if( key == '3' ) buf[2] = KEY_3;
	else
	if( key == '4' ) buf[2] = KEY_4;
	else
	if( key == '5' ) buf[2] = KEY_5;
	else
	if( key == '6' ) buf[2] = KEY_6;
	else
	if( key == '7' ) buf[2] = KEY_7;
	else
	if( key == '8' ) buf[2] = KEY_8;
	else
	if( key == '9' ) buf[2] = KEY_9;
	// SPECIAL KEY
	else
	if( key == ' ' ) buf[2] = KEY_SPACE;
	else
	if( key == '\n' ) buf[2] = KEY_ENTER;
	else
	if( key == '\t' ) buf[2] = KEY_TAB;
	else
	if( key == '~' ) buf[2] = KEY_TILDE;
	else
	if( key == '`' ) buf[2] = KEY_TILDE, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == ')' ) buf[2] = KEY_0, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '!' ) buf[2] = KEY_1, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '@' ) buf[2] = KEY_2, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '#' ) buf[2] = KEY_3, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '$' ) buf[2] = KEY_4, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '%' ) buf[2] = KEY_5, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '^' ) buf[2] = KEY_6, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '&' ) buf[2] = KEY_7, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '*' ) buf[2] = KEY_8, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '(' ) buf[2] = KEY_9, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '-' ) buf[2] = KEY_MINUS;
	else
	if( key == '=' ) buf[2] = KEY_EQUAL;
	else
	if( key == '+' ) buf[2] = KEY_EQUAL, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '[' ) buf[2] = KEY_LEFT_BRACE;
	else
	if( key == ']' ) buf[2] = KEY_RIGHT_BRACE;
	else
	if( key == '\\' ) buf[2] = KEY_SLASH;
	else
	if( key == ';' ) buf[2] = KEY_SEMICOLON;
	else
	if( key == '\'' ) buf[2] = KEY_QUOTE;
	else
	if( key == ',' ) buf[2] = KEY_COMMA;
	else
	if( key == '.' ) buf[2] = KEY_PERIOD;
	else
	if( key == '/' ) buf[2] = KEY_BACKSLASH;
	else
	if( key == '{' ) buf[2] = KEY_LEFT_BRACE, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '}' ) buf[2] = KEY_RIGHT_BRACE, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '|' ) buf[2] = KEY_SLASH, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == ':' ) buf[2] = KEY_SEMICOLON, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '"' ) buf[2] = KEY_QUOTE, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '<' ) buf[2] = KEY_COMMA, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '>' ) buf[2] = KEY_PERIOD, buf[0] = MODIFIERKEY_SHIFT;
	else
	if( key == '?' ) buf[2] = KEY_BACKSLASH, buf[0] = MODIFIERKEY_SHIFT;
	// NO KEY	
	else buf[2] = 0;
	
	sendKey();
}

void pressSpecialKey(uint8_t key, uint8_t mod = 0)
{
	buf[0] = mod;
	buf[2] = key;
	sendKey();
}

void blink()
{
	digitalWrite(PIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(20);               // wait for a second
  	digitalWrite(PIN_LED, LOW);    // turn the LED off by making the voltage LOW
  	delay(20); 
}

void setup() 
{
	pinMode(PIN_LED, OUTPUT);
    Serial.begin(9600);
    delay(200);
}

char *command = "cmd.exe\necho Hell'o Victim\nexit\n";

void loop() 
{
    delay(3000);
    int i=0;
 	
    blink();
    
 	//pressSpecialKey(KEY_MEDIA_EJECT);
 	   
    pressKey('r', MODIFIERKEY_GUI);
    
    while (command[i] != '\0') 
    {
    	if( command[i] == '\n' ) delay(50);
		pressKey(command[i]);	
		blink();

		i++;
    }
}
