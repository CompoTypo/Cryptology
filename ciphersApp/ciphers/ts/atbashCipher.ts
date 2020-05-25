export function AtbashCipher(plainTextInput: string): string {
    let output: string = '';
    for (let i: number = 0; i < plainTextInput.length; ++i) {
        let c: number = plainTextInput[i].charCodeAt(0);
        if (c > 64 && c < 91) { // capital letters
            c = 90 - (c - 65);
            output += String.fromCharCode(c);
        } else if (c > 96 && c < 123) { // lower case letters
            c = 122 - (c - 97);
            output += String.fromCharCode(c);
        } else {
            output += String.fromCharCode(c);
        }
    }
    return output;
};