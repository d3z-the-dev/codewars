class RomanNumerals {
    static fromRoman(num) {
        const dict = { M: 1000, D: 500, C: 100, L: 50, X: 10, V: 5, I: 1 };
        return num.split('').reduce((acc, curr, i, arr) => {
            const currVal = dict[curr];
            const nextVal = dict[arr[i+1]];
            if (nextVal && currVal < nextVal) return acc - currVal;
            return acc + currVal;
        }, 0);
    }

    static toRoman(num) {
        const roman = [
            ['','I','II','III','IV','V','VI','VII','VIII','IX'], 
            ['','X','XX','XXX','XL','L','LX','LXX','LXXX','XC'], 
            ['','C','CC','CCC','CD','D','DC','DCC','DCCC','CM'], 
            ['','M','MM','MMM']
        ];
        const digits = num.toString().split('').reverse();
        let romanNum = '';
        for (let i = 0; i < digits.length; i++) {
            romanNum = roman[i][parseInt(digits[i])] + romanNum;
        }
        return romanNum;
    }
}
