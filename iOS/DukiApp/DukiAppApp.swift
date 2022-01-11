//
//  DukiAppApp.swift
//  DukiApp
//
//  Created by Christoph Aldrian on 11.01.22.
//

import SwiftUI
import CDukiCalculations
import dukicalculations

@main
struct DukiAppApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
                .onAppear {
//                    print(Shared().text)
                    something()
                }
        }
    }
}
