export function encode(unciphered: string): string {
    let output: string = "";
    for (let i = 0; i < unciphered.length; i++) {
        let c = unciphered[i];
        output += String.fromCharCode(c.charCodeAt(0) + 3);
    }
    return output;
}

export function decode(ciphered: string): string {
    let output: string = "";
    for (let i = 0; i < ciphered.length; i++) {
        let c = ciphered[i];
        output += String.fromCharCode(c.charCodeAt(0) - 3);
    }
    return output;
}