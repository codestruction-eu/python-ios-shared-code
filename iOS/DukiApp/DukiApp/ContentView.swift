//
//  ContentView.swift
//  DukiApp
//
//  Created by Christoph Aldrian on 12.01.22.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        Text("pi_approx(10000): \(pi_approx(10000))")
            .padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
