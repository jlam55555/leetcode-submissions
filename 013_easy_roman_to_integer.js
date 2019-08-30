/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    
    let symbols = { I: 1,
                    V: 5,
                    X: 10,
                    L: 50,
                    C: 100,
                    D: 500,
                    M: 1000
                  };
    
    let i,
        len = s.length,
        sum = 0,
        c,
        queue = [];
    
    for(i = 0; i <= len; i++) {
        c = i == len ? 0 : symbols[s.charAt(i)];
        
        if(queue.length && (c < queue[0] || i == len))
            switch(queue.length) {
                case 3:
                    sum += 3 * queue.pop();
                    queue.pop();
                    queue.pop();
                    break;
                case 2:
                    let n1 = queue.pop();
                    let n2 = queue.pop();
                    sum += n1 == n2 ? 2 * n1 : n2 - n1;
                    break;
                case 1:
                    sum += queue.pop();
            }
        
        queue.unshift(c);
    }
    
    return sum;
    
};
