    var mysqrt = Module.cwrap('mysqrtc','number',['number']);
    return {
        mysqrt: mysqrt
    };
}));