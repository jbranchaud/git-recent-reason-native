type foreground_color =
  | BLACK
  | RED
  | GREEN
  | YELLOW
  | BLUE
  | MAGENTA
  | CYAN
  | WHITE
  | GRAY
  | RED_BRIGHT
  | GREEN_BRIGHT
  | YELLOW_BRIGHT
  | BLUE_BRIGHT
  | MAGENTA_BRIGHT
  | CYAN_BRIGHT
  | WHITE_BRIGHT;

let make = (color: foreground_color, str: string) => {
  let (open_code, close_code) =
    switch (color) {
    | BLACK => ("30", "39")
    | RED => ("31", "39")
    | GREEN => ("32", "39")
    | YELLOW => ("33", "39")
    | BLUE => ("34", "39")
    | MAGENTA => ("35", "39")
    | CYAN => ("36", "39")
    | WHITE => ("37", "39")
    | GRAY => ("90", "39")
    | RED_BRIGHT => ("91", "39")
    | GREEN_BRIGHT => ("92", "39")
    | YELLOW_BRIGHT => ("93", "39")
    | BLUE_BRIGHT => ("94", "39")
    | MAGENTA_BRIGHT => ("95", "39")
    | CYAN_BRIGHT => ("96", "39")
    | WHITE_BRIGHT => ("97", "39")
    };

  let concat_list = ["\027[", open_code, "m", str, "\027[", close_code, "m"];
  String.concat("", concat_list);
};

/* Identity */
let none = (str: string) => str;

/* Colors */
let black = (str: string) => make(BLACK, str); /* black: [30, 39] */
let red = (str: string) => make(RED, str); /* red: [31, 39] */
let green = (str: string) => make(GREEN, str); /* green: [32, 39] */
let yellow = (str: string) => make(YELLOW, str); /* yellow: [33, 39] */
let blue = (str: string) => make(BLUE, str); /* blue: [34, 39] */
let magenta = (str: string) => make(MAGENTA, str); /* magenta: [35, 39] */
let cyan = (str: string) => make(CYAN, str); /* cyan: [36, 39] */
let white = (str: string) => make(WHITE, str); /* white: [37, 39] */
let gray = (str: string) => make(GRAY, str); /* gray: [90, 39] */

/* Bright colors */
let red_bright = (str: string) => make(RED_BRIGHT, str); /* redBright: [91, 39] */
let green_bright = (str: string) => make(GREEN_BRIGHT, str); /* greenBright: [92, 39] */
let yellow_bright = (str: string) => make(YELLOW_BRIGHT, str); /* yellowBright: [93, 39] */
let blue_bright = (str: string) => make(BLUE_BRIGHT, str); /* blueBright: [94, 39] */
let magenta_bright = (str: string) => make(MAGENTA_BRIGHT, str); /* magentaBright: [95, 39] */
let cyan_bright = (str: string) => make(CYAN_BRIGHT, str); /* cyanBright: [96, 39] */
let white_bright = (str: string) => make(WHITE_BRIGHT, str); /* whiteBright: [97, 39] */