@g_global = external global i32, align 4


define i32 @ps3_random_number() {
    ret i32 42
}

define i32 @add_42(i32 %n) {
    %1 = add i32 %n, 42
    ret i32 %1
}

define i32 @bytes_to_bits(i32 %n) {
    %1 = mul i32 %n, 8
    ret i32 %1
}

define i32 @vm_operation(i1 %do_add, i32 %x, i32 %y) {
    %retval = alloca i32, align 4
    switch i1 %do_add, label %sw.default [
        i1 1, label %sw.add
    ]

    sw.add:
        %1 = add i32 %x, %y
        store i32 %1, ptr %retval, align 4
        br label %return_func

    sw.default:
        %2 = sub i32 %x, %y
        store i32 %2, ptr %retval, align 4
        br label %return_func

    return_func:
        %3 = load i32, ptr %retval, align 4
        ret i32 %3

}


define void @pass_to_store_value(i32 %n) {
    store i32 %n, i32 @g_stored, align 4
    ret void
}

define i32 @upper_32_bits(i64 %n) {
    unreachable
}
