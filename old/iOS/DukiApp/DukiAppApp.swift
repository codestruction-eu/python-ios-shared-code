//
//  DukiAppApp.swift
//  DukiApp
//
//  Created by Christoph Aldrian on 11.01.22.
//

import SwiftUI
import CDukiCalculations

@main
struct DukiAppApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
                .onAppear {
                    var array: [Int64] = [9, 8, 7, 6]
                    let str = demo(true, 10, 1.23, &array, array.count).map {
                        String(cString: $0)
                    }
                    print("String from library: \(str ?? "<NULL>")")
                }
        }
    }
}
