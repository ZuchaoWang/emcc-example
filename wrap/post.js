    var mysqrt = Module.cwrap('mysqrtC','number',['number']),
        mysqrtArray = Module.cwrap('mysqrtArrayC','undefined',['number','number','number']),
        createMyClass = Module.cwrap('createMyClassC','number',[]),
        deleteMyClass = Module.cwrap('deleteMyClassC','undefined',['number']),
        setMyClassValue = Module.cwrap('setMyClassValueC','undefined',['number','number']),
        getMyClassAnswer = Module.cwrap('getMyClassAnswerC','number',['number']);
    
    return {
        mysqrt: mysqrt,
        mysqrtArray: function (a) {
            var nDataBytes = a.length * Float32Array.BYTES_PER_ELEMENT,
                aHeap = Module._malloc(nDataBytes),
                bHeap = Module._malloc(nDataBytes),
                b = new Array(a.length),
                i;
            
            for (i = 0; i < a.length; i++) {
                Module.setValue(aHeap + i * Float32Array.BYTES_PER_ELEMENT, a[i], 'float');
            }
            
            mysqrtArray(a.length, aHeap, bHeap);
            
            for (i = 0; i < a.length; i++) {
                b[i] = Module.getValue(bHeap + i * Float32Array.BYTES_PER_ELEMENT, 'float');
            }
            
            Module._free(aHeap);
            Module._free(bHeap);
            
            return b;
        },
        createMyClass: createMyClass,
        deleteMyClass: deleteMyClass,
        setMyClassValue: setMyClassValue,
        getMyClassAnswer: getMyClassAnswer
    };
}));