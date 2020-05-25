import * as affineCipher from './affineCipher';
import { AtbashCipher } from './atbashCipher';
import * as binaryCipher from './binaryCipher';
import * as ceaserCipher from './ceaserCipher';
import * as vigenereCipher from './vigenereCipher';

let test_str: string = "hello world";

let af_enc = affineCipher.encode(test_str);
let af_dec = affineCipher.decode(af_enc);
if (af_dec != test_str) {
    console.error('mismatch', test_str + '\n', af_dec + '\n');
} else {
    console.log('MAYBE', test_str, af_dec);
}

let ab_enc = AtbashCipher(test_str);
let ab_dec = AtbashCipher(ab_enc);
if (ab_dec != test_str) {
    console.error('mismatch', test_str + '\n', ab_dec + '\n');
} else {
    console.log('MAYBE', test_str, ab_dec);
}

let ce_enc = ceaserCipher.encode(test_str);
let ce_dec = ceaserCipher.decode(ce_enc);
if (ce_dec != test_str) {
    console.error('mismatch', test_str + '\n', ce_dec + '\n');
} else {
    console.log('MAYBE', test_str, ce_dec);
}
