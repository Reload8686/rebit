// Copyright 2021 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// Flags: --harmony-temporal

let ret = "foo bar";
let d1 = new Temporal.PlainDateTime(2021, 12, 11, 1, 2, 3, 4, 5, 6,
    {era: function(like) {return ret;}});

assertEquals(ret, d1.era);
